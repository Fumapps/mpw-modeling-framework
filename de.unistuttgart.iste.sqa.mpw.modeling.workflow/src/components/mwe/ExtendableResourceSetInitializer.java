package components.mwe;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

import org.apache.log4j.Logger;
import org.eclipse.xtext.mwe.RuntimeResourceSetInitializer;

import com.google.inject.Inject;

import components.helpers.EclipsePathHelper;

class ExtendableResourceSetInitializer extends RuntimeResourceSetInitializer {
	protected final static Logger log = Logger.getLogger(ExtendableResourceSetInitializer.class.getName());
	
	@Inject
	private Mwe2ParamsMap paramsMap;
	
	public List<String> getClassPathEntries() {
        List<String> classPathEntries = super.getClassPathEntries();
        
        String additionalArchivesPaths = paramsMap.getParams().get("additionalArchivesPaths");
        if (additionalArchivesPaths == null) {
        	return classPathEntries;
        }
        
        var additionalArchivesPathParts = additionalArchivesPaths.split(";");
        for (String additionalArchivesPath : additionalArchivesPathParts) {
        	var jars = collectAdditionalJars(additionalArchivesPath);
        	classPathEntries.addAll(jars);
        }

        return classPathEntries;
    }
	
	private List<String> collectAdditionalJars(String additionalArchivesPath) {
        var additionalEntries = new ArrayList<String>();
        
        var path = EclipsePathHelper.toJavaCompatibleAbsoluteFilePath(additionalArchivesPath);
        path = Path.of(path).toAbsolutePath().toString();
		log.info("searching additional jars in: " + path);
		
		try {
			List<String> additionalJars = getAdditionalJars(path);
			log.info("found additional jars: " + additionalJars);
			additionalEntries.addAll(additionalJars);
		} catch (IOException e) {
			log.error("failed to process additional archives", e);
		}
        return additionalEntries;
	}
	
	private List<String> getAdditionalJars(String path) throws IOException {
        return Files.list(Path.of(path))
        		.map(p -> p.toAbsolutePath().toString())
        		.filter(p -> p.endsWith("jar"))
        		.collect(Collectors.toList());
	}
}