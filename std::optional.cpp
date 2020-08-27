#include <optional>
#include <map>
#include <iostream>

template <typename Map, typename Key>
std::optional< typename Map::value_type::second_type > TryFind( const Map& m, const Key& k)
{
	auto it = m.find(k);
	if (it != m.end())
		return std::make_optional(it->second);
	return std::nullopt;
}

int main()
{
	std::map< std::string, int > mm{ { "hello", 10 }, { "super", 42 } };
	auto ov = TryFind( mm, "hllo" );

	// one:
	std::cout << ov.value_or(0) << std::endl;

//	// two:
//	if (ov)
//		std::cout << *ov << std::endl;

	return 0;
}


