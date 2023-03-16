/*
** EPITECH PROJECT, 2022
** TEK
** File description:
** thread
*/

#ifndef THREAD_HPP_
    #define THREAD_HPP_
    #include <pthread.h>

    class Pthread {
        public:
            Pthread();
            ~Pthread();
            void create(pthread_t thread, void *(*function)(void *), void *arg);
            void join(pthread_t thread);
            void exit(void *status);
    };


#endif /* !THREAD_HPP_ */
