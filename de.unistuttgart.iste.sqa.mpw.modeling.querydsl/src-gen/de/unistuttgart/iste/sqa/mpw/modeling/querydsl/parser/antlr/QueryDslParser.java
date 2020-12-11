/*
 * generated by Xtext 2.23.0
 */
package de.unistuttgart.iste.sqa.mpw.modeling.querydsl.parser.antlr;

import com.google.inject.Inject;
import de.unistuttgart.iste.sqa.mpw.modeling.querydsl.parser.antlr.internal.InternalQueryDslParser;
import de.unistuttgart.iste.sqa.mpw.modeling.querydsl.services.QueryDslGrammarAccess;
import org.eclipse.xtext.parser.antlr.AbstractAntlrParser;
import org.eclipse.xtext.parser.antlr.XtextTokenStream;

public class QueryDslParser extends AbstractAntlrParser {

	@Inject
	private QueryDslGrammarAccess grammarAccess;

	@Override
	protected void setInitialHiddenTokens(XtextTokenStream tokenStream) {
		tokenStream.setInitialHiddenTokens("RULE_WS", "RULE_ML_COMMENT", "RULE_SL_COMMENT");
	}
	

	@Override
	protected InternalQueryDslParser createParser(XtextTokenStream stream) {
		return new InternalQueryDslParser(stream, getGrammarAccess());
	}

	@Override 
	protected String getDefaultRuleName() {
		return "Model";
	}

	public QueryDslGrammarAccess getGrammarAccess() {
		return this.grammarAccess;
	}

	public void setGrammarAccess(QueryDslGrammarAccess grammarAccess) {
		this.grammarAccess = grammarAccess;
	}
}
