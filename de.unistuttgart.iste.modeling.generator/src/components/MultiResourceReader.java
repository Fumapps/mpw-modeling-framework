package components;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import org.apache.log4j.Logger;
import org.eclipse.emf.ecore.resource.ResourceSet;
import org.eclipse.emf.ecore.resource.impl.ResourceSetImpl;
import org.eclipse.emf.mwe.core.WorkflowContext;
import org.eclipse.emf.mwe.core.issues.Issues;
import org.eclipse.emf.mwe.core.lib.WorkflowComponentWithModelSlot;
import org.eclipse.emf.mwe.core.monitor.ProgressMonitor;
import org.eclipse.emf.mwe.utils.Reader;

import com.google.common.base.CaseFormat;

/**
 * Base reader class which loads multiple EMF resources of a project in the workspace. 
 */
public abstract class MultiResourceReader extends WorkflowComponentWithModelSlot {
	protected final static Logger log = Logger.getLogger(MultiResourceReader.class.getName());
	
	private final String fileExtension;
	
	private String projectName;
	private String projectSubPath;
	private Set<String> excludeModels = new HashSet<>();
	
	protected MultiResourceReader(String fileExtension, String defaultSubPath) {
		if (!fileExtension.matches("\\.\\w+")) {
			throw new IllegalArgumentException("invalid fileExtension: " + fileExtension);
		}
		this.fileExtension = fileExtension;
		this.projectSubPath = defaultSubPath;
	}

	public String getProjectName() {
		return projectName;
	}

	public void setProjectName(String baseUri) {
		this.projectName = baseUri;
	}
	
	public String getProjectSubPath() {
		return projectSubPath;
	}

	public void setProjectSubPath(String projectSubPath) {
		this.projectSubPath = projectSubPath;
	}
	
	public void addExcludeModel(String modelName) {
		if (!modelName.endsWith(fileExtension)) {
			modelName += fileExtension;
		}
		excludeModels.add(modelName);
	}

	@Override
	protected void invokeInternal(WorkflowContext context, ProgressMonitor monitor, Issues issues) {
		log.info("searching " + getModelNameFromExtension() + " models for base URI: " + getBaseUri());
		
		String targetDirectory = "../" + projectName + "/" + projectSubPath;
		try (var files = listFiles(targetDirectory)) {
			
			var modelNames = files.map(f -> f.toFile().getName())
			     .filter(f -> f.endsWith(fileExtension))
			     .filter(f -> !excludeModels.contains(f))
			     .collect(Collectors.toList());
			
			modelNames.forEach(fileName -> {
				log.info("found: " + fileName);
			});
			
			addModelsToSlot(context, modelNames);
		} catch (IOException e) {
			log.error("Failed to locate " + getModelNameFromExtension() + " files under: " + targetDirectory, e);
		}
	}

	private void addModelsToSlot(WorkflowContext context, List<String> modelNames) {
		String baseUri = getBaseUri();
		ResourceSet resourceSet = new ResourceSetImpl();
		var models = new ArrayList<Object>();
		
		for (var modelName : modelNames) {
			var uri = baseUri + modelName;
			boolean firstElementOnly = true;
			var object = Reader.load(resourceSet, uri, firstElementOnly);
			models.add(object);
		}

		context.set(getModelSlot(), models);
	}
	
	private static Stream<Path> listFiles(String directory) throws IOException {
		return Files.list(Path.of(directory));
	}
	
	private String getBaseUri() {
		return "platform:/resource/" + projectName + "/" + projectSubPath + "/";
	}
	
	private String getModelNameFromExtension() {
		return CaseFormat.LOWER_CAMEL.to(CaseFormat.UPPER_CAMEL, fileExtension.substring(1));
	}
	
}