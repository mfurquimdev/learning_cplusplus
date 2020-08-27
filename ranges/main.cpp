#include <algorithm>
#include <iostream>
#include <vector>
#include <range/v3/view/filter.hpp>
#include <range/v3/view/transform.hpp>


int main()
{
	std::vector< int > numbers = { 1, 2, 3, 4, 5 };

	auto results = numbers | ranges::view::filter( []( int n ){ return n % 2 == 0; } )
		                    | ranges::view::transform( []( int n ){ return n * 2; } );

	for ( int n : results )
	{
		std::cout << n << ' ';
	}
}
