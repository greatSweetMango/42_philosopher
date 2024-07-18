# 스레드와 뮤텍스를 사용해 철학자들 구현하기
* 한명 이상의 철학자가 둥근 테이블에 앉아 다음 행동중 하나를 취함 (먹기, 자기, 생각하기)
* 철학자들은 양손에 포크가 있어야 먹을 수 있다
* 철학자가 밥을 다 먹었으면, 포크를 내려놓고 잠자기 시작
* 철학자가 잠을 다 잤으면, 생각하기 시작
* 철학자가 한 명이라도 사망하면 시뮬레이션이 종료

# 실행방법
### makefile을 사용해 프로그램을 빌드해주세요.
```
make all
```
### philo 프로그램이 생성됐다면, 필요한 인자에 맞춰 매개변수로 프로그램을 실행시켜주세요.
```
./philo [철학자의 수] [철학자의 수명] [먹는데 필요한 시간] [자는데 필요한 시간] [몇 번 먹고 종료할 것인지]
```

# 실행결과
```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
200 3 is sleeping
200 1 is sleeping
200 2 has taken a fork
200 2 has taken a fork
200 2 is eating
200 4 has taken a fork
200 4 has taken a fork
200 4 is eating
300 3 is thinking
300 1 is thinking
400 4 is sleeping
400 2 is sleeping
400 1 has taken a fork
400 1 has taken a fork
400 1 is eating
400 3 has taken a fork
400 3 has taken a fork
400 3 is eating
500 4 is thinking
500 2 is thinking
600 1 is sleeping
600 3 is sleeping
600 4 has taken a fork
600 4 has taken a fork
600 4 is eating
600 2 has taken a fork
600 2 has taken a fork
600 2 is eating
700 3 is thinking
700 1 is thinking
800 4 is sleeping
800 2 is sleeping
800 1 has taken a fork
800 1 has taken a fork
800 1 is eating
800 3 has taken a fork
800 3 has taken a fork
800 3 is eating
900 2 is thinking
900 4 is thinking
1000 1 is sleeping
1000 2 has taken a fork
1000 3 is sleeping
1000 4 has taken a fork
1000 4 has taken a fork
1000 2 has taken a fork
1000 2 is eating
1000 4 is eating
```

<img width="1350" alt="image" src="https://github.com/user-attachments/assets/745200b5-ef82-4122-94a0-410ccabd5d2d">
