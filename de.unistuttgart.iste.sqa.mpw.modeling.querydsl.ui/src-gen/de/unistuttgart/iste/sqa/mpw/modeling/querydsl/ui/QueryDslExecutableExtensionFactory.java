/*
 * generated by Xtext 2.23.0
 */
package de.unistuttgart.iste.sqa.mpw.modeling.querydsl.ui;

import com.google.inject.Injector;
import de.unistuttgart.iste.sqa.mpw.modeling.querydsl.ui.internal.QuerydslActivator;
import org.eclipse.core.runtime.Platform;
import org.eclipse.xtext.ui.guice.AbstractGuiceAwareExecutableExtensionFactory;
import org.osgi.framework.Bundle;

/**
 * This class was generated. Customizations should only happen in a newly
 * introduced subclass. 
 */
public class QueryDslExecutableExtensionFactory extends AbstractGuiceAwareExecutableExtensionFactory {

	@Override
	protected Bundle getBundle() {
		return Platform.getBundle(QuerydslActivator.PLUGIN_ID);
	}
	
	@Override
	protected Injector getInjector() {
		QuerydslActivator activator = QuerydslActivator.getInstance();
		return activator != null ? activator.getInjector(QuerydslActivator.DE_UNISTUTTGART_ISTE_SQA_MPW_MODELING_QUERYDSL_QUERYDSL) : null;
	}

}
