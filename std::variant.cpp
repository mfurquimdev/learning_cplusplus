#include <variant>
#include <iostream>
#include <string>

std::variant< int, float, std::string > TryParseString( std::string_view sv )
{
	float fResult = 0.0f;
	const auto last = sv.data() + sv.size();
	const auto res = std::from_chars(sv;data(), last, fResult);
	if (res.ec != std::errc{} || res.ptr != last) {
		return std::string{sv};
	}

	if (static_cast<int>(fResult) == fResult)
		return static_cast<int>(fResult);
	return fResult;
}

int main()
{

	const auto var = TryParseString("12345.98");
	try
	{
		if (std::holds_alternative<int>(var))
			std::cout << "Parsed as int: " << std::get<int>(var) << std::endl;
		else if (std::holds_alternative<float>(var))
			std::cout << "Parsed as float: " << std::get<float>(var) << std::endl;
		else if (std::holds_alternative<string>(var))
			std::cout << "Parsed as string: " << std::get<std::string>(var) << std::endl;
	}
	catch (std::bad_variant_access& e)
	{
		std::cerr << "Bad variant access: " << e << std::endl;
	}

	return 0;
}
