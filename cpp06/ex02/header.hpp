#ifndef HEADER_HPP
# define HEADER_HPP

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <iostream>
# include <unistd.h>

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
