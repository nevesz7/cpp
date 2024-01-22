#include "Harl.hpp"

int main(void)
{
	Harl	complainer;

	complainer.complain("test");

	complainer.complain("debug");
	complainer.complain("INFO");
	complainer.complain("Warning");
	complainer.complain("ErRoR");
}