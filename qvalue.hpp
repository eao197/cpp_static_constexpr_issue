#pragma once

#include <cstdint>

namespace qvalue_details
{

using underlying_uint_t = std::uint_least16_t;

constexpr underlying_uint_t maximum = 1000u;
constexpr underlying_uint_t zero = 0u;

enum class extremum_min_t { minimum };
enum class extremum_max_t { maximum };

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

	static constexpr qvalue_details::extremum_max_t maximum
			= qvalue_details::extremum_max_t::maximum;

	static constexpr qvalue_details::extremum_min_t zero
			= qvalue_details::extremum_min_t::minimum;

private :
	underlying_uint_t m_value{};

public :

	constexpr qvalue_t() = default;

	constexpr qvalue_t( trusted val ) noexcept
		:	m_value{ val.get() }
	{}

	constexpr qvalue_t( qvalue_details::extremum_max_t ) noexcept
		:	m_value{ qvalue_details::maximum }
	{}

	constexpr qvalue_t( qvalue_details::extremum_min_t ) noexcept
		:	m_value{ qvalue_details::zero }
	{}

	constexpr auto as_uint() const noexcept { return m_value; }
};

