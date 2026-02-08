#include <spdlog/spdlog.h>
#include <unicode/unistr.h>
#include <unicode/ustream.h>

#include <iostream>

int main()
{
	std::cout << "vckpg-manifest" << std::endl;

	spdlog::info("spdlog is working!");

	icu::UnicodeString unicode = icu::UnicodeString::fromUTF8("hello icu!");
	std::cout << unicode << std::endl;
}