/**
 * generated by Xtext 2.23.0
 */
package de.unistuttgart.iste.sqa.mpw.modeling.querydsl.querydsl;

import org.eclipse.emf.common.util.EList;

/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Context</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link de.unistuttgart.iste.sqa.mpw.modeling.querydsl.querydsl.Context#getClassName <em>Class Name</em>}</li>
 *   <li>{@link de.unistuttgart.iste.sqa.mpw.modeling.querydsl.querydsl.Context#getElements <em>Elements</em>}</li>
 * </ul>
 *
 * @see de.unistuttgart.iste.sqa.mpw.modeling.querydsl.querydsl.QuerydslPackage#getContext()
 * @model
 * @generated
 */
public interface Context extends Model
{
  /**
   * Returns the value of the '<em><b>Class Name</b></em>' attribute.
   * <!-- begin-user-doc -->
   * <!-- end-user-doc -->
   * @return the value of the '<em>Class Name</em>' attribute.
   * @see #setClassName(String)
   * @see de.unistuttgart.iste.sqa.mpw.modeling.querydsl.querydsl.QuerydslPackage#getContext_ClassName()
   * @model
   * @generated
   */
  String getClassName();

  /**
   * Sets the value of the '{@link de.unistuttgart.iste.sqa.mpw.modeling.querydsl.querydsl.Context#getClassName <em>Class Name</em>}' attribute.
   * <!-- begin-user-doc -->
   * <!-- end-user-doc -->
   * @param value the new value of the '<em>Class Name</em>' attribute.
   * @see #getClassName()
   * @generated
   */
  void setClassName(String value);

  /**
   * Returns the value of the '<em><b>Elements</b></em>' containment reference list.
   * The list contents are of type {@link de.unistuttgart.iste.sqa.mpw.modeling.querydsl.querydsl.Element}.
   * <!-- begin-user-doc -->
   * <!-- end-user-doc -->
   * @return the value of the '<em>Elements</em>' containment reference list.
   * @see de.unistuttgart.iste.sqa.mpw.modeling.querydsl.querydsl.QuerydslPackage#getContext_Elements()
   * @model containment="true"
   * @generated
   */
  EList<Element> getElements();

} // Context