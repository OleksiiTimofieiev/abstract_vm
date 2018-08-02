#include "Parser.hpp"

/* class creation routines ************************************************************************************************************************** */

Parser::Parser () {}
Parser::~Parser()	{}

Parser &Parser::operator=(Parser const &rhs)
{
	if (this != &rhs)
		_filtered_input = rhs._filtered_input;
	return *this;
}

Parser::Parser(Parser const &src)
{
	*this = src;
}

/* read input routines ********************************************************************************************************************** */

bool	Parser::detect_input_stream( const int quantity_of_arguments ) const
{
	if ( quantity_of_arguments == 2)
		return ( true );
	return ( false );
}

void	Parser::read_from_the_standart_input( void )
{
	ssize_t			line_number = 1;
	std::string		input;
	int				reading = true;
	size_t			comment_find;
	size_t 			found;
		
	std::string whitespaces(" \t\f\v\n\r");

	while( reading )
	{
		printf( "%ld. ", line_number++ );

		comment_find = 0;

		if ( std::getline( std::cin, input ) )
		{
			if (input.at(0) != ';' && input.at(1) != ';')
			{
				comment_find = input.find(";");

				if (comment_find != std::string::npos)
				{
					input.erase(comment_find, input.length());

					found = input.find_last_not_of(whitespaces);

					if (found != std::string::npos)
						input.erase(found + 1);
				}
			}
			_filtered_input.push_back(input);

			if (input == ";;")
				break;
		}
		else
			reading = false;
	}
	std::cout << "\x1B[35mParsing has been finished => [ avm ] \033[1;32m✓\x1B[0m" << std::endl;
}

void	Parser::read_from_the_ifstream( char * argument )
{
	std::string	path = 	argument;
	std::ifstream		fin;
	std::string			input = "";
	size_t 				comment_find;
	size_t found;

	std::string whitespaces(" \t\f\v\n\r");

	fin.open(path);

	if ( !fin.is_open() )
	{
		std::cout << "No such file. Program was terminated." << std::endl;;
		exit(0);
	}
	else
	{
		while( !( fin.eof() ) )
		{
			getline( fin, input);

			if (input.at(0) != ';' && input.at(1) != ';')
			{
				comment_find = input.find(";");

				if (comment_find != std::string::npos)
				{
					input.erase(comment_find, input.length());

					found = input.find_last_not_of(whitespaces);

					if (found != std::string::npos)
						input.erase(found + 1);
				}
			}
			_filtered_input.push_back(input);
			if (input == "exit")
				break;
		}
	}
	fin.close();

	std::cout << "\x1B[35mParsing has been finished => [ avm ] \033[1;32m✓\x1B[0m" << std::endl;
}

void Parser::read( const int quantity_of_arguments, char * argument )
{
	if ( detect_input_stream( quantity_of_arguments ) )
		read_from_the_ifstream( argument );
	else
		read_from_the_standart_input();
}

/* infrastructure ******************************************************************************************************************* */

void	Parser::print_list( void )
{
	std::cout << std::endl;
	std::cout << std::endl;

	if ( !_filtered_input.empty() )
	{
		for ( auto i = _filtered_input.cbegin(); i != _filtered_input.cend(); ++i )
			std::cout << *i << std::endl;
	}

	std::cout << std::endl;
}
