/**
 */
package generationAnnotations;


/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Property Path Annotation</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link generationAnnotations.PropertyPathAnnotation#getPropertyPath <em>Property Path</em>}</li>
 * </ul>
 *
 * @see generationAnnotations.GenerationAnnotationsPackage#getPropertyPathAnnotation()
 * @model
 * @generated
 */
public interface PropertyPathAnnotation extends GenerationAnnotation {
	/**
	 * Returns the value of the '<em><b>Property Path</b></em>' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @return the value of the '<em>Property Path</em>' attribute.
	 * @see #setPropertyPath(String)
	 * @see generationAnnotations.GenerationAnnotationsPackage#getPropertyPathAnnotation_PropertyPath()
	 * @model required="true"
	 * @generated
	 */
	String getPropertyPath();

	/**
	 * Sets the value of the '{@link generationAnnotations.PropertyPathAnnotation#getPropertyPath <em>Property Path</em>}' attribute.
	 * <!-- begin-user-doc -->
	 * <!-- end-user-doc -->
	 * @param value the new value of the '<em>Property Path</em>' attribute.
	 * @see #getPropertyPath()
	 * @generated
	 */
	void setPropertyPath(String value);

} // PropertyPathAnnotation
