#pragma once

#include <cstdint>

namespace qvalue_details
{

using underlying_uint_t = std::uint_least16_t;

constexpr underlying_uint_t maximum = 1000u;
constexpr underlying_uint_t zero = 0u;

class trusted
{
	const underlying_uint_t m_value;

public :
	explicit constexpr
	trusted( underlying_uint_t value ) noexcept : m_value{ value } {}

	constexpr auto get() const noexcept { return m_value; }
};

} /* namespace qvalue_details */

class qvalue_t
{
public :
	using underlying_uint_t = qvalue_details::underlying_uint_t;
	using trusted = qvalue_details::trusted;

	static constexpr trusted maximum{ qvalue_details::maximum };
	static constexpr trusted zero{ qvalue_details::zero };

private :
	underlying_uint_t m_value{};

public :

	constexpr qvalue_t() = default;

	constexpr qvalue_t( trusted val ) noexcept
		:	m_value{ val.get() }
	{}

	constexpr auto as_uint() const noexcept { return m_value; }
};

