#include <pthread.h>
#include <iostream>
#include <sys/types.h>
#include <unystd.h>
#include <fcntl.h>
#include <sys/stat.h>
void *thread_func(void *arg)
{
std::cout << "Запущен новый поток\n";
while(true){}
return NULL;
}

int main()
{

std::cout << "программа запущена/n";
pid_t pid = getpid();
int fd = open("main.pid", O_CREATE | O_EXCL | O_TRUNC, 0777);
write(fd, pid, sizeof(pid));
std::cout << pid << std::endl;
close(fd);
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
