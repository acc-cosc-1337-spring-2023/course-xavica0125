#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "func.h"
#include <string>
using std::string;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify get_gc_content function")
{	
	const string dna= "AGCTATAG";
	const string dna1= "CGCTATAG";
	REQUIRE(get_gc_content(dna) == .375);
	REQUIRE(get_gc_content(dna1) == .50);
}

TEST_CASE("Verify get_reverse_string function")
{
	string dna= "AGCTATAG";
	string dna1= "CGCTATAG";
	REQUIRE(get_reverse_string(dna)=="GATATCGA");
	REQUIRE(get_reverse_string(dna1)== "GATATCGC");
}

TEST_CASE("Verify get_dna_complement function")
{	
	string dna= "AAAACCCGGT";
	string dna1= "CCCGGAAAAT";
	REQUIRE(get_dna_complement(dna)== "ACCGGGTTTT");
	REQUIRE(get_dna_complement(dna1)== "ATTTTCCGGG");
}