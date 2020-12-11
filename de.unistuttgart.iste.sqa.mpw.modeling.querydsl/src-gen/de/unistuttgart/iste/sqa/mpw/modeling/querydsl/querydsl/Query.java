/**
 * generated by Xtext 2.23.0
 */
package de.unistuttgart.iste.sqa.mpw.modeling.querydsl.querydsl;


/**
 * <!-- begin-user-doc -->
 * A representation of the model object '<em><b>Query</b></em>'.
 * <!-- end-user-doc -->
 *
 * <p>
 * The following features are supported:
 * </p>
 * <ul>
 *   <li>{@link de.unistuttgart.iste.sqa.mpw.modeling.querydsl.querydsl.Query#isInternal <em>Internal</em>}</li>
 *   <li>{@link de.unistuttgart.iste.sqa.mpw.modeling.querydsl.querydsl.Query#getParameterList <em>Parameter List</em>}</li>
 * </ul>
 *
 * @see de.unistuttgart.iste.sqa.mpw.modeling.querydsl.querydsl.QuerydslPackage#getQuery()
 * @model
 * @generated
 */
public interface Query extends Element
{
  /**
   * Returns the value of the '<em><b>Internal</b></em>' attribute.
   * <!-- begin-user-doc -->
   * <!-- end-user-doc -->
   * @return the value of the '<em>Internal</em>' attribute.
   * @see #setInternal(boolean)
   * @see de.unistuttgart.iste.sqa.mpw.modeling.querydsl.querydsl.QuerydslPackage#getQuery_Internal()
   * @model
   * @generated
   */
  boolean isInternal();

  /**
   * Sets the value of the '{@link de.unistuttgart.iste.sqa.mpw.modeling.querydsl.querydsl.Query#isInternal <em>Internal</em>}' attribute.
   * <!-- begin-user-doc -->
   * <!-- end-user-doc -->
   * @param value the new value of the '<em>Internal</em>' attribute.
   * @see #isInternal()
   * @generated
   */
  void setInternal(boolean value);

  /**
   * Returns the value of the '<em><b>Parameter List</b></em>' containment reference.
   * <!-- begin-user-doc -->
   * <!-- end-user-doc -->
   * @return the value of the '<em>Parameter List</em>' containment reference.
   * @see #setParameterList(ParameterList)
   * @see de.unistuttgart.iste.sqa.mpw.modeling.querydsl.querydsl.QuerydslPackage#getQuery_ParameterList()
   * @model containment="true"
   * @generated
   */
  ParameterList getParameterList();

  /**
   * Sets the value of the '{@link de.unistuttgart.iste.sqa.mpw.modeling.querydsl.querydsl.Query#getParameterList <em>Parameter List</em>}' containment reference.
   * <!-- begin-user-doc -->
   * <!-- end-user-doc -->
   * @param value the new value of the '<em>Parameter List</em>' containment reference.
   * @see #getParameterList()
   * @generated
   */
  void setParameterList(ParameterList value);

} // Query
