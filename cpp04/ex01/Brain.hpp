#ifndef BRAIN_HPP
# define BRAIN_HPP

# define CAT_IDEAS ((char const*[]) { "Cat idea #00", "Cat idea #01", "Cat idea #02", "Cat idea #03", "Cat idea #04", "Cat idea #05", "Cat idea #06", "Cat idea #07", "Cat idea #08", "Cat idea #09", "Cat idea #10", "Cat idea #11", "Cat idea #12", "Cat idea #13", "Cat idea #14", "Cat idea #15", "Cat idea #16", "Cat idea #17", "Cat idea #18", "Cat idea #19", "Cat idea #20", "Cat idea #21", "Cat idea #22", "Cat idea #23", "Cat idea #24", "Cat idea #25", "Cat idea #26", "Cat idea #27", "Cat idea #28", "Cat idea #29", "Cat idea #30", "Cat idea #31", "Cat idea #32", "Cat idea #33", "Cat idea #34", "Cat idea #35", "Cat idea #36", "Cat idea #37", "Cat idea #38", "Cat idea #39", "Cat idea #40", "Cat idea #41", "Cat idea #42", "Cat idea #43", "Cat idea #44", "Cat idea #45", "Cat idea #46", "Cat idea #47", "Cat idea #48", "Cat idea #49", "Cat idea #50", "Cat idea #51", "Cat idea #52", "Cat idea #53", "Cat idea #54", "Cat idea #55", "Cat idea #56", "Cat idea #57", "Cat idea #58", "Cat idea #59", "Cat idea #60", "Cat idea #61", "Cat idea #62", "Cat idea #63", "Cat idea #64", "Cat idea #65", "Cat idea #66", "Cat idea #67", "Cat idea #68", "Cat idea #69", "Cat idea #70", "Cat idea #71", "Cat idea #72", "Cat idea #73", "Cat idea #74", "Cat idea #75", "Cat idea #76", "Cat idea #77", "Cat idea #78", "Cat idea #79", "Cat idea #80", "Cat idea #81", "Cat idea #82", "Cat idea #83", "Cat idea #84", "Cat idea #85", "Cat idea #86", "Cat idea #87", "Cat idea #88", "Cat idea #89", "Cat idea #90", "Cat idea #91", "Cat idea #92", "Cat idea #93", "Cat idea #94", "Cat idea #95", "Cat idea #96", "Cat idea #97", "Cat idea #98", "Cat idea #99" })

# define DOG_IDEAS ((char const*[]) { "Dog idea #00", "Dog idea #01", "Dog idea #02", "Dog idea #03", "Dog idea #04", "Dog idea #05", "Dog idea #06", "Dog idea #07", "Dog idea #08", "Dog idea #09", "Dog idea #10", "Dog idea #11", "Dog idea #12", "Dog idea #13", "Dog idea #14", "Dog idea #15", "Dog idea #16", "Dog idea #17", "Dog idea #18", "Dog idea #19", "Dog idea #20", "Dog idea #21", "Dog idea #22", "Dog idea #23", "Dog idea #24", "Dog idea #25", "Dog idea #26", "Dog idea #27", "Dog idea #28", "Dog idea #29", "Dog idea #30", "Dog idea #31", "Dog idea #32", "Dog idea #33", "Dog idea #34", "Dog idea #35", "Dog idea #36", "Dog idea #37", "Dog idea #38", "Dog idea #39", "Dog idea #40", "Dog idea #41", "Dog idea #42", "Dog idea #43", "Dog idea #44", "Dog idea #45", "Dog idea #46", "Dog idea #47", "Dog idea #48", "Dog idea #49", "Dog idea #50", "Dog idea #51", "Dog idea #52", "Dog idea #53", "Dog idea #54", "Dog idea #55", "Dog idea #56", "Dog idea #57", "Dog idea #58", "Dog idea #59", "Dog idea #60", "Dog idea #61", "Dog idea #62", "Dog idea #63", "Dog idea #64", "Dog idea #65", "Dog idea #66", "Dog idea #67", "Dog idea #68", "Dog idea #69", "Dog idea #70", "Dog idea #71", "Dog idea #72", "Dog idea #73", "Dog idea #74", "Dog idea #75", "Dog idea #76", "Dog idea #77", "Dog idea #78", "Dog idea #79", "Dog idea #80", "Dog idea #81", "Dog idea #82", "Dog idea #83", "Dog idea #84", "Dog idea #85", "Dog idea #86", "Dog idea #87", "Dog idea #88", "Dog idea #89", "Dog idea #90", "Dog idea #91", "Dog idea #92", "Dog idea #93", "Dog idea #94", "Dog idea #95", "Dog idea #96", "Dog idea #97", "Dog idea #98", "Dog idea #99" })

# include <iostream>
# include <cstdlib>

class Brain
{
	protected:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &brain);
		virtual ~Brain();

		std::string getIdea() const;
		std::string getIdea(int index) const;
		std::string	getIdea(int index, std::string type) const;
		void		setIdea(int index, std::string idea);
};

#endif