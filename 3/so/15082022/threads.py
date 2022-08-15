import threading
from time import sleep

s1 = threading.Semaphore(1)
s2 = threading.Semaphore(1)


def execute_thread_1():
    s1.acquire()
    for index in range(10):
        print(f"(Thread 1) Thread: {index}")
        sleep(1)
    s1.release()
    print(f"(Thread 1) Finalizando...")


def execute_thread_2():
    s1.acquire()
    for index in range(10):
        print(f"(Thread 2) Thread: {index}")
        sleep(1.5)
    s1.release()
    print(f"(Thread 2) Finalizando...")


def execute_thread_3():
    s2.acquire()
    for index in range(10):
        print(f"(Thread 3) Thread: {index}")
        sleep(0.5)
    s2.release()
    print(f"(Thread 3) Finalizando...")


def execute_thread_4(time: float):
    s2.acquire()
    for index in range(10):
        print(f"(Thread 4) Thread: {index}")
        sleep(time)
    s2.release()
    print(f"(Thread 4) Finalizando...")


t1 = threading.Thread(target=execute_thread_1)
t2 = threading.Thread(target=execute_thread_2)
t3 = threading.Thread(target=execute_thread_3)
t4 = threading.Thread(target=execute_thread_4, args=[0.5])
t1.start()
t2.start()
t3.start()
t4.start()
