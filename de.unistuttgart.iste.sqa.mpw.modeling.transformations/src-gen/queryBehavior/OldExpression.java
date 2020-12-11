/**
 */
package queryBehavior;


/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Old Expression</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link queryBehavior.OldExpression#getInner <em>Inner</em>}</li>
 * </ul>
 *
 * @see queryBehavior.QueryPackage#getOldExpression()
 * @model
 * @generated
 */
public interface OldExpression extends Expression {
	/**
	 * Returns the value of the '<em><b>Inner</b></em>' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Inner</em>' containment reference.
	 * @see #setInner(Expression)
	 * @see queryBehavior.QueryPackage#getOldExpression_Inner()
	 * @model containment="true" required="true"
	 * @generated
	 */
	Expression getInner();

	/**
	 * Sets the value of the '{@link queryBehavior.OldExpression#getInner <em>Inner</em>}' containment reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Inner</em>' containment reference.
	 * @see #getInner()
	 * @generated
	 */
	void setInner(Expression value);

} // OldExpression
