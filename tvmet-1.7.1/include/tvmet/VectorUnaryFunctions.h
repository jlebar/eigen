/*
 * Tiny Vector Matrix Library
 * Dense Vector Matrix Libary of Tiny size using Expression Templates
 *
 * Copyright (C) 2001 - 2003 Olaf Petzold <opetzold@users.sourceforge.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * $Id: VectorUnaryFunctions.h,v 1.9 2004/06/10 16:36:55 opetzold Exp $
 */

#ifndef TVMET_VECTOR_UNARY_FUNCTIONS_H
#define TVMET_VECTOR_UNARY_FUNCTIONS_H

namespace tvmet {


/*********************************************************
 * PART I: DECLARATION
 *********************************************************/

/*
 * unary_function(Vector<std::complex<T>, Sz>)
 */
#if defined(EIGEN_USE_COMPLEX)
#define TVMET_DECLARE_MACRO(NAME)					\
template<class T, int Sz>					\
XprVector<								\
  XprUnOp<								\
    Fcnl_##NAME< std::complex<T> >,					\
    VectorConstReference<std::complex<T>, Sz>				\
  >,									\
  Sz									\
>									\
NAME(const Vector<std::complex<T>, Sz>& rhs) _tvmet_always_inline;

TVMET_DECLARE_MACRO(real)
TVMET_DECLARE_MACRO(imag)
TVMET_DECLARE_MACRO(conj)

#undef TVMET_DECLARE_MACRO

#endif // defined(EIGEN_USE_COMPLEX)


/*********************************************************
 * PART II: IMPLEMENTATION
 *********************************************************/


/*
 * unary_function(Vector<std::complex<T>, Sz>)
 */
#if defined(EIGEN_USE_COMPLEX)
#define TVMET_IMPLEMENT_MACRO(NAME)					\
template<class T, int Sz>					\
inline									\
XprVector<								\
  XprUnOp<								\
    Fcnl_##NAME< std::complex<T> >,					\
    VectorConstReference<std::complex<T>, Sz>				\
  >,									\
  Sz									\
>									\
NAME(const Vector<std::complex<T>, Sz>& rhs) {				\
  typedef XprUnOp<							\
      Fcnl_##NAME< std::complex<T> >,					\
      VectorConstReference<std::complex<T>, Sz>				\
    > 							expr_type;	\
    return XprVector<expr_type, Sz>(expr_type(rhs.const_ref()));	\
}

TVMET_IMPLEMENT_MACRO(real)
TVMET_IMPLEMENT_MACRO(imag)
TVMET_IMPLEMENT_MACRO(conj)

#undef TVMET_IMPLEMENT_MACRO

#endif // defined(EIGEN_USE_COMPLEX)


} // namespace tvmet

#endif // TVMET_VECTOR_UNARY_FUNCTIONS_H

// Local Variables:
// mode:C++
// End:
