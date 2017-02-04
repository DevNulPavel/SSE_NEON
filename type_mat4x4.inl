///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2005 - 2014 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref core
/// @file glm/core/type_mat4x4.inl
/// @date 2005-01-27 / 2011-06-15
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

namespace glm{
namespace detail
{
#if defined(_MSC_VER)
	using namespace DirectX;
#endif
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR length_t tmat4x4<T, P>::length() const
	{
		return 4;
	}

	//////////////////////////////////////
	// Accesses

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER typename tmat4x4<T, P>::col_type &
	tmat4x4<T, P>::operator[]
	(
		length_t i
	)
	{
		assert(i < this->length());
		return this->value[i];
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER typename tmat4x4<T, P>::col_type const &
	tmat4x4<T, P>::operator[]
	(
		length_t i
	) const
	{
		assert(i < this->length());
		return this->value[i];
	}

	//////////////////////////////////////////////////////////////
	// Constructors

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>::tmat4x4()
	{
		T Zero(0);
		T One(1);
		this->value[0] = col_type(One, Zero, Zero, Zero);
		this->value[1] = col_type(Zero, One, Zero, Zero);
		this->value[2] = col_type(Zero, Zero, One, Zero);
		this->value[3] = col_type(Zero, Zero, Zero, One);
	}
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>::tmat4x4
	(
		tmat4x4<T, P> const & m
	)
	{
		this->value[0] = m[0];
		this->value[1] = m[1];
		this->value[2] = m[2];
		this->value[3] = m[3];
	}

	template <typename T, precision P>
	template <precision Q>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>::tmat4x4
	(
		tmat4x4<T, Q> const & m
	)
	{
		this->value[0] = m[0];
		this->value[1] = m[1];
		this->value[2] = m[2];
		this->value[3] = m[3];
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>::tmat4x4
	(
		ctor
	)
	{}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>::tmat4x4
	(
		T const & s
	)
	{
		value_type const Zero(0);
		this->value[0] = col_type(s, Zero, Zero, Zero);
		this->value[1] = col_type(Zero, s, Zero, Zero);
		this->value[2] = col_type(Zero, Zero, s, Zero);
		this->value[3] = col_type(Zero, Zero, Zero, s);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>::tmat4x4
	(
		T const & x0, T const & y0, T const & z0, T const & w0,
		T const & x1, T const & y1, T const & z1, T const & w1,
		T const & x2, T const & y2, T const & z2, T const & w2,
		T const & x3, T const & y3, T const & z3, T const & w3
	)
	{
		this->value[0] = col_type(x0, y0, z0, w0);
		this->value[1] = col_type(x1, y1, z1, w1);
		this->value[2] = col_type(x2, y2, z2, w2);
		this->value[3] = col_type(x3, y3, z3, w3);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>::tmat4x4
	(
		col_type const & v0,
		col_type const & v1,
		col_type const & v2,
		col_type const & v3
	)
	{
		this->value[0] = v0;
		this->value[1] = v1;
		this->value[2] = v2;
		this->value[3] = v3;
	}

	template <typename T, precision P>
	template <typename U, precision Q>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>::tmat4x4
	(
		tmat4x4<U, Q> const & m
	)
	{
		this->value[0] = col_type(m[0]);
		this->value[1] = col_type(m[1]);
		this->value[2] = col_type(m[2]);
		this->value[3] = col_type(m[3]);
	}

	//////////////////////////////////////
	// Conversion constructors
	template <typename T, precision P> 
	template <
		typename X1, typename Y1, typename Z1, typename W1,
		typename X2, typename Y2, typename Z2, typename W2,
		typename X3, typename Y3, typename Z3, typename W3,
		typename X4, typename Y4, typename Z4, typename W4>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>::tmat4x4
	(
		X1 const & x1, Y1 const & y1, Z1 const & z1, W1 const & w1,
		X2 const & x2, Y2 const & y2, Z2 const & z2, W2 const & w2,
		X3 const & x3, Y3 const & y3, Z3 const & z3, W3 const & w3,
		X4 const & x4, Y4 const & y4, Z4 const & z4, W4 const & w4
	)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<X1>::is_iec559 || std::numeric_limits<X1>::is_integer, "*mat4x4 constructor only takes float and integer types, 1st parameter type invalid.");
		GLM_STATIC_ASSERT(std::numeric_limits<Y1>::is_iec559 || std::numeric_limits<Y1>::is_integer, "*mat4x4 constructor only takes float and integer types, 2nd parameter type invalid.");
		GLM_STATIC_ASSERT(std::numeric_limits<Z1>::is_iec559 || std::numeric_limits<Z1>::is_integer, "*mat4x4 constructor only takes float and integer types, 3rd parameter type invalid.");
		GLM_STATIC_ASSERT(std::numeric_limits<W1>::is_iec559 || std::numeric_limits<W1>::is_integer, "*mat4x4 constructor only takes float and integer types, 4th parameter type invalid.");

		GLM_STATIC_ASSERT(std::numeric_limits<X2>::is_iec559 || std::numeric_limits<X2>::is_integer, "*mat4x4 constructor only takes float and integer types, 5th parameter type invalid.");
		GLM_STATIC_ASSERT(std::numeric_limits<Y2>::is_iec559 || std::numeric_limits<Y2>::is_integer, "*mat4x4 constructor only takes float and integer types, 6th parameter type invalid.");
		GLM_STATIC_ASSERT(std::numeric_limits<Z2>::is_iec559 || std::numeric_limits<Z2>::is_integer, "*mat4x4 constructor only takes float and integer types, 7th parameter type invalid.");
		GLM_STATIC_ASSERT(std::numeric_limits<W2>::is_iec559 || std::numeric_limits<W2>::is_integer, "*mat4x4 constructor only takes float and integer types, 8th parameter type invalid.");

		GLM_STATIC_ASSERT(std::numeric_limits<X3>::is_iec559 || std::numeric_limits<X3>::is_integer, "*mat4x4 constructor only takes float and integer types, 9th parameter type invalid.");
		GLM_STATIC_ASSERT(std::numeric_limits<Y3>::is_iec559 || std::numeric_limits<Y3>::is_integer, "*mat4x4 constructor only takes float and integer types, 10th parameter type invalid.");
		GLM_STATIC_ASSERT(std::numeric_limits<Z3>::is_iec559 || std::numeric_limits<Z3>::is_integer, "*mat4x4 constructor only takes float and integer types, 11th parameter type invalid.");
		GLM_STATIC_ASSERT(std::numeric_limits<W3>::is_iec559 || std::numeric_limits<W3>::is_integer, "*mat4x4 constructor only takes float and integer types, 12th parameter type invalid.");

		GLM_STATIC_ASSERT(std::numeric_limits<X4>::is_iec559 || std::numeric_limits<X4>::is_integer, "*mat4x4 constructor only takes float and integer types, 13th parameter type invalid.");
		GLM_STATIC_ASSERT(std::numeric_limits<Y4>::is_iec559 || std::numeric_limits<Y4>::is_integer, "*mat4x4 constructor only takes float and integer types, 14th parameter type invalid.");
		GLM_STATIC_ASSERT(std::numeric_limits<Z4>::is_iec559 || std::numeric_limits<Z4>::is_integer, "*mat4x4 constructor only takes float and integer types, 15th parameter type invalid.");
		GLM_STATIC_ASSERT(std::numeric_limits<W4>::is_iec559 || std::numeric_limits<W4>::is_integer, "*mat4x4 constructor only takes float and integer types, 16th parameter type invalid.");

		this->value[0] = col_type(static_cast<T>(x1), value_type(y1), value_type(z1), value_type(w1));
		this->value[1] = col_type(static_cast<T>(x2), value_type(y2), value_type(z2), value_type(w2));
		this->value[2] = col_type(static_cast<T>(x3), value_type(y3), value_type(z3), value_type(w3));
		this->value[3] = col_type(static_cast<T>(x4), value_type(y4), value_type(z4), value_type(w4));
	}
	
	template <typename T, precision P>
	template <typename V1, typename V2, typename V3, typename V4>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>::tmat4x4
	(
		tvec4<V1, P> const & v1,
		tvec4<V2, P> const & v2,
		tvec4<V3, P> const & v3,
		tvec4<V4, P> const & v4
	)		
	{
		GLM_STATIC_ASSERT(std::numeric_limits<V1>::is_iec559 || std::numeric_limits<V1>::is_integer, "*mat4x4 constructor only takes float and integer types, 1st parameter type invalid.");
		GLM_STATIC_ASSERT(std::numeric_limits<V2>::is_iec559 || std::numeric_limits<V2>::is_integer, "*mat4x4 constructor only takes float and integer types, 2nd parameter type invalid.");
		GLM_STATIC_ASSERT(std::numeric_limits<V3>::is_iec559 || std::numeric_limits<V3>::is_integer, "*mat4x4 constructor only takes float and integer types, 3rd parameter type invalid.");
		GLM_STATIC_ASSERT(std::numeric_limits<V4>::is_iec559 || std::numeric_limits<V4>::is_integer, "*mat4x4 constructor only takes float and integer types, 4th parameter type invalid.");

		this->value[0] = col_type(v1);
		this->value[1] = col_type(v2);
		this->value[2] = col_type(v3);
		this->value[3] = col_type(v4);
	}

	//////////////////////////////////////
	// Matrix convertion constructors
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>::tmat4x4
	(
		tmat2x2<T, P> const & m
	)
	{
		this->value[0] = col_type(m[0], detail::tvec2<T, P>(0));
		this->value[1] = col_type(m[1], detail::tvec2<T, P>(0));
		this->value[2] = col_type(static_cast<T>(0));
		this->value[3] = col_type(static_cast<T>(0), value_type(0), value_type(0), value_type(1));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>::tmat4x4
	(
		tmat3x3<T, P> const & m
	)
	{
		this->value[0] = col_type(m[0], value_type(0));
		this->value[1] = col_type(m[1], value_type(0));
		this->value[2] = col_type(m[2], value_type(0));
		this->value[3] = col_type(static_cast<T>(0), value_type(0), value_type(0), value_type(1));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>::tmat4x4
	(
		tmat2x3<T, P> const & m
	)
	{
		this->value[0] = col_type(m[0], value_type(0));
		this->value[1] = col_type(m[1], value_type(0));
		this->value[2] = col_type(static_cast<T>(0));
		this->value[3] = col_type(static_cast<T>(0), value_type(0), value_type(0), value_type(1));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>::tmat4x4
	(
		tmat3x2<T, P> const & m
	)
	{
		this->value[0] = col_type(m[0], detail::tvec2<T, P>(0));
		this->value[1] = col_type(m[1], detail::tvec2<T, P>(0));
		this->value[2] = col_type(m[2], detail::tvec2<T, P>(0));
		this->value[3] = col_type(static_cast<T>(0), value_type(0), value_type(0), value_type(1));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>::tmat4x4
	(
		tmat2x4<T, P> const & m
	)
	{
		this->value[0] = m[0];
		this->value[1] = m[1];
		this->value[2] = col_type(T(0));
		this->value[3] = col_type(T(0), T(0), T(0), T(1));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>::tmat4x4
	(
		tmat4x2<T, P> const & m
	)
	{
		this->value[0] = col_type(m[0], detail::tvec2<T, P>(0));
		this->value[1] = col_type(m[1], detail::tvec2<T, P>(0));
		this->value[2] = col_type(T(0));
		this->value[3] = col_type(T(0), T(0), T(0), T(1));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>::tmat4x4
	(
		tmat3x4<T, P> const & m
	)
	{
		this->value[0] = m[0];
		this->value[1] = m[1];
		this->value[2] = m[2];
		this->value[3] = col_type(T(0), T(0), T(0), T(1));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>::tmat4x4
	(
		tmat4x3<T, P> const & m
	)
	{
		this->value[0] = col_type(m[0], T(0));
		this->value[1] = col_type(m[1], T(0));
		this->value[2] = col_type(m[2], T(0));
		this->value[3] = col_type(m[3], T(1));
	}

	//////////////////////////////////////////////////////////////
	// Operators

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>& tmat4x4<T, P>::operator=
	(
		tmat4x4<T, P> const & m
	)
	{
		//memcpy could be faster
		//memcpy(&this->value, &m.value, 16 * sizeof(valType));
		this->value[0] = m[0];
		this->value[1] = m[1];
		this->value[2] = m[2];
		this->value[3] = m[3];
		return *this;
	}

	template <typename T, precision P> 
	template <typename U> 
	GLM_FUNC_QUALIFIER tmat4x4<T, P>& tmat4x4<T, P>::operator=
	(
		tmat4x4<U, P> const & m
	)
	{
		//memcpy could be faster
		//memcpy(&this->value, &m.value, 16 * sizeof(valType));
		this->value[0] = m[0];
		this->value[1] = m[1];
		this->value[2] = m[2];
		this->value[3] = m[3];
		return *this;
	}

	template <typename T, precision P>
	template <typename U>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>& tmat4x4<T, P>::operator+= (U s)
	{
		this->value[0] += s;
		this->value[1] += s;
		this->value[2] += s;
		this->value[3] += s;
		return *this;
	}

	template <typename T, precision P>
	template <typename U>
	GLM_FUNC_QUALIFIER tmat4x4<T, P>& tmat4x4<T, P>::operator+= (tmat4x4<U, P> const & m)
	{
		this->value[0] += m[0];
		this->value[1] += m[1];
		this->value[2] += m[2];
		this->value[3] += m[3];
		return *this;
	}

	template <typename T, precision P>
	template <typename U>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> & tmat4x4<T, P>::operator-= (U s)
	{
		this->value[0] -= s;
		this->value[1] -= s;
		this->value[2] -= s;
		this->value[3] -= s;
		return *this;
	}

	template <typename T, precision P>
	template <typename U>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> & tmat4x4<T, P>::operator-= (tmat4x4<U, P> const & m)
	{
		this->value[0] -= m[0];
		this->value[1] -= m[1];
		this->value[2] -= m[2];
		this->value[3] -= m[3];
		return *this;
	}

	template <typename T, precision P>
	template <typename U>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> & tmat4x4<T, P>::operator*= (U s)
	{
		this->value[0] *= s;
		this->value[1] *= s;
		this->value[2] *= s;
		this->value[3] *= s;
		return *this;
	}

	template <typename T, precision P>
	template <typename U>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> & tmat4x4<T, P>::operator*= (tmat4x4<U, P> const & m)
	{
		return (*this = *this * m);
	}

	template <typename T, precision P>
	template <typename U>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> & tmat4x4<T, P>::operator/= (U s)
	{
		this->value[0] /= s;
		this->value[1] /= s;
		this->value[2] /= s;
		this->value[3] /= s;
		return *this;
	}

	template <typename T, precision P>
	template <typename U>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> & tmat4x4<T, P>::operator/= (tmat4x4<U, P> const & m)
	{
		return (*this = *this * detail::compute_inverse<detail::tmat4x4, T, P>::call(m));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> & tmat4x4<T, P>::operator++ ()
	{
		++this->value[0];
		++this->value[1];
		++this->value[2];
		++this->value[3];
		return *this;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> & tmat4x4<T, P>::operator-- ()
	{
		--this->value[0];
		--this->value[1];
		--this->value[2];
		--this->value[3];
		return *this;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> tmat4x4<T, P>::operator++(int)
	{
		tmat4x4<T, P> Result(*this);
		++*this;
		return Result;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> tmat4x4<T, P>::operator--(int)
	{
		tmat4x4<T, P> Result(*this);
		--*this;
		return Result;
	}

	template <typename T, precision P>
	struct compute_inverse<detail::tmat4x4, T, P>
	{
		static detail::tmat4x4<T, P> call(detail::tmat4x4<T, P> const & m)
		{
			T Coef00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
			T Coef02 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
			T Coef03 = m[1][2] * m[2][3] - m[2][2] * m[1][3];

			T Coef04 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
			T Coef06 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
			T Coef07 = m[1][1] * m[2][3] - m[2][1] * m[1][3];

			T Coef08 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
			T Coef10 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
			T Coef11 = m[1][1] * m[2][2] - m[2][1] * m[1][2];

			T Coef12 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
			T Coef14 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
			T Coef15 = m[1][0] * m[2][3] - m[2][0] * m[1][3];

			T Coef16 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
			T Coef18 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
			T Coef19 = m[1][0] * m[2][2] - m[2][0] * m[1][2];

			T Coef20 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
			T Coef22 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
			T Coef23 = m[1][0] * m[2][1] - m[2][0] * m[1][1];

			detail::tvec4<T, P> Fac0(Coef00, Coef00, Coef02, Coef03);
			detail::tvec4<T, P> Fac1(Coef04, Coef04, Coef06, Coef07);
			detail::tvec4<T, P> Fac2(Coef08, Coef08, Coef10, Coef11);
			detail::tvec4<T, P> Fac3(Coef12, Coef12, Coef14, Coef15);
			detail::tvec4<T, P> Fac4(Coef16, Coef16, Coef18, Coef19);
			detail::tvec4<T, P> Fac5(Coef20, Coef20, Coef22, Coef23);

			detail::tvec4<T, P> Vec0(m[1][0], m[0][0], m[0][0], m[0][0]);
			detail::tvec4<T, P> Vec1(m[1][1], m[0][1], m[0][1], m[0][1]);
			detail::tvec4<T, P> Vec2(m[1][2], m[0][2], m[0][2], m[0][2]);
			detail::tvec4<T, P> Vec3(m[1][3], m[0][3], m[0][3], m[0][3]);

			detail::tvec4<T, P> Inv0(Vec1 * Fac0 - Vec2 * Fac1 + Vec3 * Fac2);
			detail::tvec4<T, P> Inv1(Vec0 * Fac0 - Vec2 * Fac3 + Vec3 * Fac4);
			detail::tvec4<T, P> Inv2(Vec0 * Fac1 - Vec1 * Fac3 + Vec3 * Fac5);
			detail::tvec4<T, P> Inv3(Vec0 * Fac2 - Vec1 * Fac4 + Vec2 * Fac5);

			detail::tvec4<T, P> SignA(+1, -1, +1, -1);
			detail::tvec4<T, P> SignB(-1, +1, -1, +1);
			detail::tmat4x4<T, P> Inverse(Inv0 * SignA, Inv1 * SignB, Inv2 * SignA, Inv3 * SignB);

			detail::tvec4<T, P> Row0(Inverse[0][0], Inverse[1][0], Inverse[2][0], Inverse[3][0]);

			detail::tvec4<T, P> Dot0(m[0] * Row0);
			T Dot1 = (Dot0.x + Dot0.y) + (Dot0.z + Dot0.w);

			T OneOverDeterminant = static_cast<T>(1) / Dot1;

			return Inverse * OneOverDeterminant;
		}
	};

	// Binary operators
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> operator+
	(
		tmat4x4<T, P> const & m,
		T const & s
	)
	{
		return tmat4x4<T, P>(
			m[0] + s,
			m[1] + s,
			m[2] + s,
			m[3] + s);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> operator+
	(
		T const & s,
		tmat4x4<T, P> const & m
	)
	{
		return tmat4x4<T, P>(
			m[0] + s,
			m[1] + s,
			m[2] + s,
			m[3] + s);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> operator+
	(
		tmat4x4<T, P> const & m1,
		tmat4x4<T, P> const & m2
	)
	{
		return tmat4x4<T, P>(
			m1[0] + m2[0],
			m1[1] + m2[1],
			m1[2] + m2[2],
			m1[3] + m2[3]);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> operator-
	(
		tmat4x4<T, P> const & m,
		T const & s
	)
	{
		return tmat4x4<T, P>(
			m[0] - s,
			m[1] - s,
			m[2] - s,
			m[3] - s);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> operator-
	(
		T const & s,
		tmat4x4<T, P> const & m
	)
	{
		return tmat4x4<T, P>(
			s - m[0],
			s - m[1],
			s - m[2],
			s - m[3]);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> operator-
	(
		tmat4x4<T, P> const & m1,
		tmat4x4<T, P> const & m2
	)
	{
		return tmat4x4<T, P>(
			m1[0] - m2[0],
			m1[1] - m2[1],
			m1[2] - m2[2],
			m1[3] - m2[3]);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> operator*
	(
		tmat4x4<T, P> const & m,
		T const  & s
	)
	{
		return tmat4x4<T, P>(
			m[0] * s,
			m[1] * s,
			m[2] * s,
			m[3] * s);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> operator*
	(
		T const & s,
		tmat4x4<T, P> const & m
	)
	{
		return tmat4x4<T, P>(
			m[0] * s,
			m[1] * s,
			m[2] * s,
			m[3] * s);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER typename tmat4x4<T, P>::col_type operator*
	(
		tmat4x4<T, P> const & m,
		typename tmat4x4<T, P>::row_type const & v
	)
	{
/*
		__m128 v0 = _mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(0, 0, 0, 0));
		__m128 v1 = _mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(1, 1, 1, 1));
		__m128 v2 = _mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(2, 2, 2, 2));
		__m128 v3 = _mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(3, 3, 3, 3));

		__m128 m0 = _mm_mul_ps(m[0].data, v0);
		__m128 m1 = _mm_mul_ps(m[1].data, v1);
		__m128 a0 = _mm_add_ps(m0, m1);

		__m128 m2 = _mm_mul_ps(m[2].data, v2);
		__m128 m3 = _mm_mul_ps(m[3].data, v3);
		__m128 a1 = _mm_add_ps(m2, m3);

		__m128 a2 = _mm_add_ps(a0, a1);

		return typename tmat4x4<T, P>::col_type(a2);
*/
#if defined(USE_NEON)
        float32x4x4_t iMatrix;

	    iMatrix.val[0] = vmulq_n_f32(*(float32x4_t*)&m[0].x, (float32_t)v[0]);
	    
	    iMatrix.val[0] = vmlaq_n_f32(iMatrix.val[0], *(float32x4_t*)&m[1].x, (float32_t)v[1]);
	    iMatrix.val[0] = vmlaq_n_f32(iMatrix.val[0], *(float32x4_t*)&m[2].x, (float32_t)v[2]);
	    iMatrix.val[0] = vmlaq_n_f32(iMatrix.val[0], *(float32x4_t*)&m[3].x, (float32_t)v[3]);

        
        return *(typename tmat4x4<T, P>::col_type *)&iMatrix.val[0];
#elif defined(_MSC_VER)
		XMFLOAT4X4 fm;
		memcpy((u8*)&fm, (u8*)&m[0].x, sizeof(float) * 4 * 4);
		return *(typename tmat4x4<T, P>::col_type *)&XMVector4Transform(XMLoadFloat4((XMFLOAT4*)&v.x), XMLoadFloat4x4(&fm));
#else
		typename tmat4x4<T, P>::col_type const Mov0(v[0]);
		typename tmat4x4<T, P>::col_type const Mov1(v[1]);
		typename tmat4x4<T, P>::col_type const Mul0 = m[0] * Mov0;
		typename tmat4x4<T, P>::col_type const Mul1 = m[1] * Mov1;
		typename tmat4x4<T, P>::col_type const Add0 = Mul0 + Mul1;
		typename tmat4x4<T, P>::col_type const Mov2(v[2]);
		typename tmat4x4<T, P>::col_type const Mov3(v[3]);
		typename tmat4x4<T, P>::col_type const Mul2 = m[2] * Mov2;
		typename tmat4x4<T, P>::col_type const Mul3 = m[3] * Mov3;
		typename tmat4x4<T, P>::col_type const Add1 = Mul2 + Mul3;
		typename tmat4x4<T, P>::col_type const Add2 = Add0 + Add1;
		return Add2;
#endif
/*
		return typename tmat4x4<T, P>::col_type(
			m[0][0] * v[0] + m[1][0] * v[1] + m[2][0] * v[2] + m[3][0] * v[3],
			m[0][1] * v[0] + m[1][1] * v[1] + m[2][1] * v[2] + m[3][1] * v[3],
			m[0][2] * v[0] + m[1][2] * v[1] + m[2][2] * v[2] + m[3][2] * v[3],
			m[0][3] * v[0] + m[1][3] * v[1] + m[2][3] * v[2] + m[3][3] * v[3]);
*/
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER typename tmat4x4<T, P>::row_type operator*
	(
		typename tmat4x4<T, P>::col_type const & v,
		tmat4x4<T, P> const & m
	)
	{
		return typename tmat4x4<T, P>::row_type(
			m[0][0] * v[0] + m[0][1] * v[1] + m[0][2] * v[2] + m[0][3] * v[3],
			m[1][0] * v[0] + m[1][1] * v[1] + m[1][2] * v[2] + m[1][3] * v[3],
			m[2][0] * v[0] + m[2][1] * v[1] + m[2][2] * v[2] + m[2][3] * v[3],
			m[3][0] * v[0] + m[3][1] * v[1] + m[3][2] * v[2] + m[3][3] * v[3]);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat2x4<T, P> operator*
	(
		tmat4x4<T, P> const & m1,
		tmat2x4<T, P> const & m2
	)
	{
		return tmat2x4<T, P>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3]);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat3x4<T, P> operator*
	(
		tmat4x4<T, P> const & m1,
		tmat3x4<T, P> const & m2
	)
	{
		return tmat3x4<T, P>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3],
			m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2] + m1[3][2] * m2[2][3],
			m1[0][3] * m2[2][0] + m1[1][3] * m2[2][1] + m1[2][3] * m2[2][2] + m1[3][3] * m2[2][3]);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> operator*
	(
		tmat4x4<T, P> const & m1,
		tmat4x4<T, P> const & m2
	)
	{
#if defined(USE_NEON)
        // float32x4x4_t m;

        // m.val[0] = vmulq_n_f32(*(float32x4_t*)&m1[0].x, vgetq_lane_f32(*(float32x4_t*)&m2[0].x, 0));
        // m.val[1] = vmulq_n_f32(*(float32x4_t*)&m1[0].x, vgetq_lane_f32(*(float32x4_t*)&m2[1].x, 0));
        // m.val[2] = vmulq_n_f32(*(float32x4_t*)&m1[0].x, vgetq_lane_f32(*(float32x4_t*)&m2[2].x, 0));
        // m.val[3] = vmulq_n_f32(*(float32x4_t*)&m1[0].x, vgetq_lane_f32(*(float32x4_t*)&m2[3].x, 0));
        
        // m.val[0] = vmlaq_n_f32(m.val[0], *(float32x4_t*)&m1[1].x, vgetq_lane_f32(*(float32x4_t*)&m2[0].x, 1));
        // m.val[1] = vmlaq_n_f32(m.val[1], *(float32x4_t*)&m1[1].x, vgetq_lane_f32(*(float32x4_t*)&m2[1].x, 1));
        // m.val[2] = vmlaq_n_f32(m.val[2], *(float32x4_t*)&m1[1].x, vgetq_lane_f32(*(float32x4_t*)&m2[2].x, 1));
        // m.val[3] = vmlaq_n_f32(m.val[3], *(float32x4_t*)&m1[1].x, vgetq_lane_f32(*(float32x4_t*)&m2[3].x, 1));
        
        // m.val[0] = vmlaq_n_f32(m.val[0], *(float32x4_t*)&m1[2].x, vgetq_lane_f32(*(float32x4_t*)&m2[0].x, 2));
        // m.val[1] = vmlaq_n_f32(m.val[1], *(float32x4_t*)&m1[2].x, vgetq_lane_f32(*(float32x4_t*)&m2[1].x, 2));
        // m.val[2] = vmlaq_n_f32(m.val[2], *(float32x4_t*)&m1[2].x, vgetq_lane_f32(*(float32x4_t*)&m2[2].x, 2));
        // m.val[3] = vmlaq_n_f32(m.val[3], *(float32x4_t*)&m1[2].x, vgetq_lane_f32(*(float32x4_t*)&m2[3].x, 2));
        
        // m.val[0] = vmlaq_n_f32(m.val[0], *(float32x4_t*)&m1[3].x, vgetq_lane_f32(*(float32x4_t*)&m2[0].x, 3));
        // m.val[1] = vmlaq_n_f32(m.val[1], *(float32x4_t*)&m1[3].x, vgetq_lane_f32(*(float32x4_t*)&m2[1].x, 3));
        // m.val[2] = vmlaq_n_f32(m.val[2], *(float32x4_t*)&m1[3].x, vgetq_lane_f32(*(float32x4_t*)&m2[2].x, 3));
        // m.val[3] = vmlaq_n_f32(m.val[3], *(float32x4_t*)&m1[3].x, vgetq_lane_f32(*(float32x4_t*)&m2[3].x, 3));
        
        // return *(tmat4x4<T, P> *)&m;

	tmat4x4<T, P> result(tmat4x4<T, P>::_null);

	__asm__ volatile
	(
		// Store A & B leaving room for q4-q7, which should be preserved
		"vldmia %1, { q0-q3 } \n\t"
		"vldmia %2, { q8-q11 }\n\t"

		// result = first column of B x first row of A
		"vmul.f32 q12, q8, d0[0]\n\t"
		"vmul.f32 q13, q8, d2[0]\n\t"
		"vmul.f32 q14, q8, d4[0]\n\t"
		"vmul.f32 q15, q8, d6[0]\n\t"

		// result += second column of B x second row of A
		"vmla.f32 q12, q9, d0[1]\n\t"
		"vmla.f32 q13, q9, d2[1]\n\t"
		"vmla.f32 q14, q9, d4[1]\n\t"
		"vmla.f32 q15, q9, d6[1]\n\t"

		// result += third column of B x third row of A
		"vmla.f32 q12, q10, d1[0]\n\t"
		"vmla.f32 q13, q10, d3[0]\n\t"
		"vmla.f32 q14, q10, d5[0]\n\t"
		"vmla.f32 q15, q10, d7[0]\n\t"

		// result += last column of B x last row of A
		"vmla.f32 q12, q11, d1[1]\n\t"
		"vmla.f32 q13, q11, d3[1]\n\t"
		"vmla.f32 q14, q11, d5[1]\n\t"
		"vmla.f32 q15, q11, d7[1]\n\t"

		// output = result registers
		"vstmia %0, { q12-q15 }"
		
		: // no output
		: "r" (&(result[0].x)), "r" (&(m1[0].x)), "r" (&(m2[0].x)) 	// input - note *value* of pointer doesn't change
		: "memory", "q0", "q1", "q2", "q3", "q8", "q9", "q10", "q11", "q12", "q13", "q14", "q15" //clobber
	);

#elif defined(_MSC_VER)
		XMFLOAT4X4 fm1, fm2;
		memcpy((u8*)&fm1, (u8*)&m1[0].x, sizeof(float) * 4 * 4);
		memcpy((u8*)&fm2, (u8*)&m2[0].x, sizeof(float) * 4 * 4);
		return *(tmat4x4<T, P> *)&XMMatrixMultiply(XMLoadFloat4x4(&fm2), XMLoadFloat4x4(&fm1));
#else
		typename tmat4x4<T, P>::col_type const SrcA0 = m1[0];
		typename tmat4x4<T, P>::col_type const SrcA1 = m1[1];
		typename tmat4x4<T, P>::col_type const SrcA2 = m1[2];
		typename tmat4x4<T, P>::col_type const SrcA3 = m1[3];

		typename tmat4x4<T, P>::col_type const SrcB0 = m2[0];
		typename tmat4x4<T, P>::col_type const SrcB1 = m2[1];
		typename tmat4x4<T, P>::col_type const SrcB2 = m2[2];
		typename tmat4x4<T, P>::col_type const SrcB3 = m2[3];

		tmat4x4<T, P> Result(tmat4x4<T, P>::_null);
		Result[0] = SrcA0 * SrcB0[0] + SrcA1 * SrcB0[1] + SrcA2 * SrcB0[2] + SrcA3 * SrcB0[3];
		Result[1] = SrcA0 * SrcB1[0] + SrcA1 * SrcB1[1] + SrcA2 * SrcB1[2] + SrcA3 * SrcB1[3];
		Result[2] = SrcA0 * SrcB2[0] + SrcA1 * SrcB2[1] + SrcA2 * SrcB2[2] + SrcA3 * SrcB2[3];
		Result[3] = SrcA0 * SrcB3[0] + SrcA1 * SrcB3[1] + SrcA2 * SrcB3[2] + SrcA3 * SrcB3[3];
		return Result;
#endif
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> operator/
	(
		tmat4x4<T, P> const & m,
		T const & s
	)
	{
		return tmat4x4<T, P>(
			m[0] / s,
			m[1] / s,
			m[2] / s,
			m[3] / s);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> operator/
	(
		T const & s,
		tmat4x4<T, P> const & m
	)
	{
		return tmat4x4<T, P>(
			s / m[0],
			s / m[1],
			s / m[2],
			s / m[3]);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER typename tmat4x4<T, P>::col_type operator/
	(
		tmat4x4<T, P> const & m,
		typename tmat4x4<T, P>::row_type const & v
	)
	{
		return detail::compute_inverse<detail::tmat4x4, T, P>::call(m) * v;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER typename tmat4x4<T, P>::row_type operator/
	(
		typename tmat4x4<T, P>::col_type const & v,
		tmat4x4<T, P> const & m
	)
	{
		return v * detail::compute_inverse<detail::tmat4x4, T, P>::call(m);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> operator/
	(
		tmat4x4<T, P> const & m1,
		tmat4x4<T, P> const & m2
	)
	{
		tmat4x4<T, P> m1_copy(m1);
		return m1_copy /= m2;
	}

	// Unary constant operators
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> const operator-
	(
		tmat4x4<T, P> const & m
	)
	{
		return tmat4x4<T, P>(
			-m[0],
			-m[1],
			-m[2],
			-m[3]);
	}

	template <typename T, precision P> 
	GLM_FUNC_QUALIFIER tmat4x4<T, P> const operator++
	(
		tmat4x4<T, P> const & m,
		int
	)
	{
		return tmat4x4<T, P>(
			m[0] + static_cast<T>(1),
			m[1] + static_cast<T>(1),
			m[2] + static_cast<T>(1),
			m[3] + static_cast<T>(1));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tmat4x4<T, P> const operator--
	(
		tmat4x4<T, P> const & m,
		int
	)
	{
		return tmat4x4<T, P>(
			m[0] - static_cast<T>(1),
			m[1] - static_cast<T>(1),
			m[2] - static_cast<T>(1),
			m[3] - static_cast<T>(1));
	}

	//////////////////////////////////////
	// Boolean operators

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER bool operator==
	(
		tmat4x4<T, P> const & m1,
		tmat4x4<T, P> const & m2
	)
	{
		return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]) && (m1[3] == m2[3]);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER bool operator!=
	(
		tmat4x4<T, P> const & m1,
		tmat4x4<T, P> const & m2
	)
	{
		return (m1[0] != m2[0]) || (m1[1] != m2[1]) || (m1[2] != m2[2]) || (m1[3] != m2[3]);
	}

} //namespace detail
} //namespace glm
