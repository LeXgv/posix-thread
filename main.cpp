#include <pthread.h>
#include <iostream>

void *thread_func(void *arg)
{
std::cout << "Запущен новый поток\n";
while(true){}
return NULL;
}

int main()
{

std::cout << "программа запущена/n";
pthread_t p_id;
pthread_attr_t attr;
//инициализация атрибутов 
pthread_attr_init(&attr);
//запуск потока
pthread_create(&p_id, &attr, thread_func, NULL);
//ожидание потока
std::cout <<"переход в режим ожидания потока\n";
void *t;
pthread_join(p_id, &t);
return 1;
}
