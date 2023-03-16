/*
** EPITECH PROJECT, 2022
** TEK
** File description:
** error_handling
*/

#ifndef ERROR_HANDLING_HPP_
    #define ERROR_HANDLING_HPP_
    #include <iostream>
    #include <vector>
    #include <sstream>
    #include <dlfcn.h>
    #include <string.h>
    #include <stdio.h>
    class Error {
        public:
            Error(void);
            ~Error(void);
            int show_usage(void);
            int check_numbers(char *a, char *b, char *c);
            int error_handling(int argc, char **argv);
        protected:
        private:
    };

#endif /* !ERROR_HANDLING_HPP_ */
