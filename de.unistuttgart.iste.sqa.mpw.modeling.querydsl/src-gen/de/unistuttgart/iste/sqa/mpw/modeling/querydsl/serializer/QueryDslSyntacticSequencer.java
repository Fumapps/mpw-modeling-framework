/*
 * generated by Xtext 2.23.0
 */
package de.unistuttgart.iste.sqa.mpw.modeling.querydsl.serializer;

import com.google.inject.Inject;
import de.unistuttgart.iste.sqa.mpw.modeling.querydsl.services.QueryDslGrammarAccess;
import java.util.List;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.xtext.IGrammarAccess;
import org.eclipse.xtext.RuleCall;
import org.eclipse.xtext.nodemodel.INode;
import org.eclipse.xtext.serializer.analysis.GrammarAlias.AbstractElementAlias;
import org.eclipse.xtext.serializer.analysis.GrammarAlias.AlternativeAlias;
import org.eclipse.xtext.serializer.analysis.GrammarAlias.GroupAlias;
import org.eclipse.xtext.serializer.analysis.GrammarAlias.TokenAlias;
import org.eclipse.xtext.serializer.analysis.ISyntacticSequencerPDAProvider.ISynNavigable;
import org.eclipse.xtext.serializer.analysis.ISyntacticSequencerPDAProvider.ISynTransition;
import org.eclipse.xtext.serializer.sequencer.AbstractSyntacticSequencer;

@SuppressWarnings("all")
public class QueryDslSyntacticSequencer extends AbstractSyntacticSequencer {

	protected QueryDslGrammarAccess grammarAccess;
	protected AbstractElementAlias match_MethodCall_LeftParenthesisRightParenthesisKeyword_1_1_or___LeftParenthesisKeyword_1_0_0_RightParenthesisKeyword_1_0_2__;
	protected AbstractElementAlias match_PrimaryExpression_LeftParenthesisKeyword_0_0_a;
	protected AbstractElementAlias match_PrimaryExpression_LeftParenthesisKeyword_0_0_p;
	
	@Inject
	protected void init(IGrammarAccess access) {
		grammarAccess = (QueryDslGrammarAccess) access;
		match_MethodCall_LeftParenthesisRightParenthesisKeyword_1_1_or___LeftParenthesisKeyword_1_0_0_RightParenthesisKeyword_1_0_2__ = new AlternativeAlias(false, false, new GroupAlias(false, false, new TokenAlias(false, false, grammarAccess.getMethodCallAccess().getLeftParenthesisKeyword_1_0_0()), new TokenAlias(false, false, grammarAccess.getMethodCallAccess().getRightParenthesisKeyword_1_0_2())), new TokenAlias(false, false, grammarAccess.getMethodCallAccess().getLeftParenthesisRightParenthesisKeyword_1_1()));
		match_PrimaryExpression_LeftParenthesisKeyword_0_0_a = new TokenAlias(true, true, grammarAccess.getPrimaryExpressionAccess().getLeftParenthesisKeyword_0_0());
		match_PrimaryExpression_LeftParenthesisKeyword_0_0_p = new TokenAlias(true, false, grammarAccess.getPrimaryExpressionAccess().getLeftParenthesisKeyword_0_0());
	}
	
	@Override
	protected String getUnassignedRuleCallToken(EObject semanticObject, RuleCall ruleCall, INode node) {
		return "";
	}
	
	
	@Override
	protected void emitUnassignedTokens(EObject semanticObject, ISynTransition transition, INode fromNode, INode toNode) {
		if (transition.getAmbiguousSyntaxes().isEmpty()) return;
		List<INode> transitionNodes = collectNodes(fromNode, toNode);
		for (AbstractElementAlias syntax : transition.getAmbiguousSyntaxes()) {
			List<INode> syntaxNodes = getNodesFor(transitionNodes, syntax);
			if (match_MethodCall_LeftParenthesisRightParenthesisKeyword_1_1_or___LeftParenthesisKeyword_1_0_0_RightParenthesisKeyword_1_0_2__.equals(syntax))
				emit_MethodCall_LeftParenthesisRightParenthesisKeyword_1_1_or___LeftParenthesisKeyword_1_0_0_RightParenthesisKeyword_1_0_2__(semanticObject, getLastNavigableState(), syntaxNodes);
			else if (match_PrimaryExpression_LeftParenthesisKeyword_0_0_a.equals(syntax))
				emit_PrimaryExpression_LeftParenthesisKeyword_0_0_a(semanticObject, getLastNavigableState(), syntaxNodes);
			else if (match_PrimaryExpression_LeftParenthesisKeyword_0_0_p.equals(syntax))
				emit_PrimaryExpression_LeftParenthesisKeyword_0_0_p(semanticObject, getLastNavigableState(), syntaxNodes);
			else acceptNodes(getLastNavigableState(), syntaxNodes);
		}
	}

	/**
	 * Ambiguous syntax:
	 *     ('(' ')') | '()'
	 *
	 * This ambiguous syntax occurs at:
	 *     targetMethod=ID (ambiguity) (rule end)
	 */
	protected void emit_MethodCall_LeftParenthesisRightParenthesisKeyword_1_1_or___LeftParenthesisKeyword_1_0_0_RightParenthesisKeyword_1_0_2__(EObject semanticObject, ISynNavigable transition, List<INode> nodes) {
		acceptNodes(transition, nodes);
	}
	
	/**
	 * Ambiguous syntax:
	 *     '('*
	 *
	 * This ambiguous syntax occurs at:
	 *     (rule start) (ambiguity) '!' expression=PrimaryExpression
	 *     (rule start) (ambiguity) 'old' '(' expression=PropertyPathExpression
	 *     (rule start) (ambiguity) statements+=Statement
	 *     (rule start) (ambiguity) value='false'
	 *     (rule start) (ambiguity) value='null'
	 *     (rule start) (ambiguity) value='true'
	 *     (rule start) (ambiguity) value=INT
	 *     (rule start) (ambiguity) value=STRING
	 *     (rule start) (ambiguity) {AndExpression.left=}
	 *     (rule start) (ambiguity) {ComparisonExpression.left=}
	 *     (rule start) (ambiguity) {DivisionExpression.left=}
	 *     (rule start) (ambiguity) {EqualityExpression.left=}
	 *     (rule start) (ambiguity) {ImpliesExpression.left=}
	 *     (rule start) (ambiguity) {MinusExpression.left=}
	 *     (rule start) (ambiguity) {MultiplicationExpression.left=}
	 *     (rule start) (ambiguity) {OrExpression.left=}
	 *     (rule start) (ambiguity) {PlusExpression.left=}
	 */
	protected void emit_PrimaryExpression_LeftParenthesisKeyword_0_0_a(EObject semanticObject, ISynNavigable transition, List<INode> nodes) {
		acceptNodes(transition, nodes);
	}
	
	/**
	 * Ambiguous syntax:
	 *     '('+
	 *
	 * This ambiguous syntax occurs at:
	 *     (rule start) (ambiguity) {AndExpression.left=}
	 *     (rule start) (ambiguity) {ComparisonExpression.left=}
	 *     (rule start) (ambiguity) {DivisionExpression.left=}
	 *     (rule start) (ambiguity) {EqualityExpression.left=}
	 *     (rule start) (ambiguity) {ImpliesExpression.left=}
	 *     (rule start) (ambiguity) {MinusExpression.left=}
	 *     (rule start) (ambiguity) {MultiplicationExpression.left=}
	 *     (rule start) (ambiguity) {OrExpression.left=}
	 *     (rule start) (ambiguity) {PlusExpression.left=}
	 */
	protected void emit_PrimaryExpression_LeftParenthesisKeyword_0_0_p(EObject semanticObject, ISynNavigable transition, List<INode> nodes) {
		acceptNodes(transition, nodes);
	}
	
}
