/**
 */
package commandBehavior;

import org.eclipse.emf.ecore.EObject;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Attribute Condition</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link commandBehavior.AttributeCondition#getInstance <em>Instance</em>}</li>
 *   <li>{@link commandBehavior.AttributeCondition#getAttributeName <em>Attribute Name</em>}</li>
 *   <li>{@link commandBehavior.AttributeCondition#getAttributeValueLiteral <em>Attribute Value Literal</em>}</li>
 *   <li>{@link commandBehavior.AttributeCondition#isIsCreate <em>Is Create</em>}</li>
 * </ul>
 *
 * @see commandBehavior.CommandPackage#getAttributeCondition()
 * @model
 * @generated
 */
public interface AttributeCondition extends EObject {
	/**
	 * Returns the value of the '<em><b>Instance</b></em>' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Instance</em>' reference.
	 * @see #setInstance(InstanceCondition)
	 * @see commandBehavior.CommandPackage#getAttributeCondition_Instance()
	 * @model required="true"
	 * @generated
	 */
	InstanceCondition getInstance();

	/**
	 * Sets the value of the '{@link commandBehavior.AttributeCondition#getInstance <em>Instance</em>}' reference.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Instance</em>' reference.
	 * @see #getInstance()
	 * @generated
	 */
	void setInstance(InstanceCondition value);

	/**
	 * Returns the value of the '<em><b>Attribute Name</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Attribute Name</em>' attribute.
	 * @see #setAttributeName(String)
	 * @see commandBehavior.CommandPackage#getAttributeCondition_AttributeName()
	 * @model required="true"
	 * @generated
	 */
	String getAttributeName();

	/**
	 * Sets the value of the '{@link commandBehavior.AttributeCondition#getAttributeName <em>Attribute Name</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Attribute Name</em>' attribute.
	 * @see #getAttributeName()
	 * @generated
	 */
	void setAttributeName(String value);

	/**
	 * Returns the value of the '<em><b>Attribute Value Literal</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Attribute Value Literal</em>' attribute.
	 * @see #setAttributeValueLiteral(String)
	 * @see commandBehavior.CommandPackage#getAttributeCondition_AttributeValueLiteral()
	 * @model required="true"
	 * @generated
	 */
	String getAttributeValueLiteral();

	/**
	 * Sets the value of the '{@link commandBehavior.AttributeCondition#getAttributeValueLiteral <em>Attribute Value Literal</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Attribute Value Literal</em>' attribute.
	 * @see #getAttributeValueLiteral()
	 * @generated
	 */
	void setAttributeValueLiteral(String value);

	/**
	 * Returns the value of the '<em><b>Is Create</b></em>' attribute.
	 * The default value is <code>"false"</code>.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Is Create</em>' attribute.
	 * @see #setIsCreate(boolean)
	 * @see commandBehavior.CommandPackage#getAttributeCondition_IsCreate()
	 * @model default="false" required="true"
	 * @generated
	 */
	boolean isIsCreate();

	/**
	 * Sets the value of the '{@link commandBehavior.AttributeCondition#isIsCreate <em>Is Create</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Is Create</em>' attribute.
	 * @see #isIsCreate()
	 * @generated
	 */
	void setIsCreate(boolean value);

} // AttributeCondition