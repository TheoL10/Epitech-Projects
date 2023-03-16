/*
** EPITECH PROJECT, 2022
** TEK
** File description:
** mutex
*/

#ifndef MUTEX_HPP_
    #define MUTEX_HPP_
    #include "mutex"

    class Mutex {
        public:
            Mutex();
            ~Mutex();
            void lock(pthread_mutex_t mutex);
            void unlock(pthread_mutex_t mutex);
            int init(pthread_mutex_t mutex);
            int destroy(pthread_mutex_t mutex);
        protected:
        private:
    };

#endif /* !MUTEX_HPP_ */
