# Libft

자주 사용되는 C Library 함수들을 재정의 하여 나만의 C 라이브러리를 만들자.

## 구현할 함수
### ft_memset
    void    *ft_memset(void *s, int c, size_t n)

- return : 문자열 s
- 메모리의 내용을 원하는 크기만큼 특정 값으로 설정 가능하다.

- s포인터에 지정된 메모리 블록의 n 바이트 만큼을 지정된 value(c)로 채운다.

- memset 함수 내부에서 value(c)는 (unsigned char)로 다루어 진다.

- int형 값을 넣을때 원하는대로 옮겨지지 않는다.(주의)

-----
### ft_bzero
    void    ft_bzero(void *s, size_t n)

- s가 가르키는 메모리 영역을 n 바이트만큼 0으로 초기화 한다.

---
### ft_memcpy
    void    *ft_memcpy(void *dest, const void *src, size_t n)

- return : dest

- src의 메모리를 dest로 n만큼 복사한다.

- 메모리 영역은 겹치지 않아야한다. (겹치면 memmove함수를 사용.) 

- memcpy는 NULL-종료를 보장하지 않고, 정확히 n바이트 만큼 복사한다.

---
### ft_memccpy
    void    *ft_memccpy(void *dest, const void *src, int c, size_t n)

- src에서 dest로 n바이트만큼 복사한다.
- 복사하는 도중 src 에서 c 를 만났을 경우 -> dest 리턴
- 복사하는 도중 c 를 만나지 못했을 경우 -> null 리턴

---
### ft_memmove
    void    *ft_memmove(void *dest, const void *src, size_t n)

- return : dest
- src에서 dest로 n바이트 만큼 복사
1. src 의 주소값이 dest 보다 클 경우
    - 앞에서 부터 복사.
2. dest의 주소값이 src 보다 클 경우
    - 뒤에서 부터 복사.

---
### ft_memchr
    void    *ft_memchr(const void *s, int c, size_t n)

- return : c와 일치하는 값이 있을때 -> 그곳의 주소<br>
없을때 -> NULL 리턴

- 메모리 블럭에서 문자를 찾는다.

---

### ft_memcmp
    int ft_memcmp(const void *s1, const void *s2, size_t n)

- return : 두 메모리 블럭이 같을떄 : 0 리턴
            
    다를때 : 두 메모리의 차이를 리턴

- 두개의 메모리 블럭을 비교한다 n바이트 만큼 비교한다.

---

### ft_strlen
    size_t  ft_strlen(const char *s)

- return : 문자열의 길이
- 문자열의 길이를 리턴한다.
---

### ft_strlcpy
    size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)

- return : 만드려고 시도한 문자열의 총 길이(src_len)
- 크기 제한 문자열 복사
- 목적지 버퍼 전체 크기를 차지, 공간이 있으면 NULL 보장
- dstsize 가 0이 아닌경우 (dstsize - 1)만큼 문자를 복사
---

### ft_strlcat
    size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)

- return : dst의 초기 글자 수 + src의 초기 글자 수
- dst 끝에 src 문자를 덧붙인다.
- 최대 (dstsize - strlen(dst) - 1)만큼의 문자열을 붙인다.
- 예외 1 -> dstsize == 0
- 예외 2 -> dstsize <= ft_strlen(dst)
---
### ft_strchr
    char    *ft_strchr(const char *s, int c)
- return : s문자열 or null
- s 문자열 에서 c 가 있는지 앞에서 부터 찾는다.
- o : 그 위치의 주솟값 리턴 (처음으로 찾은)
- x : null 리턴
---
### ft_strrchr
    char    *ft_strrchr(const char *s, int c)
- return : c가 있는 문자열 s의 주소 or null
- s문자열에서 c가 있는지 뒤에서 부터 찾는다.
- o : 그 위치의 주솟값 리턴 (처음으로 찾은)
- x : null 리턴
---
### ft_strnstr
    char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
- haystack 문자열에서 needle 문자열이 처음으로 나타나는 곳을 찾는다.
- len 바이트만큼 에서만 검색
- '\0' 문자가 나온 다음은 검색되지 않는다.
- needle이 빈 문자열일때 : haystack 리턴
- haystack 문자열안에 needle이 없을때 : null 리턴
- neelde이 있을때 : 첫번째 needle 문자열에서 첫번째 문자 주소를 리턴

---
### ft_strncmp
    int	ft_strncmp(const char *s1, const char *s2, size_t n)
- s1 문자열과 s2 문자열을 n바이트 만큼 비교한다.
- 같을때 0을 리턴
- 다르면 s1 - s2를 리턴
---
### ft_atoi
    int			ft_atoi(const char *str)
- 문자열을 매개변수로 받아 int형으로 리턴한다.
- 0개 이상의 공백과 1개의 부호는 무시된다.
---
### ft_isalpha
    int	ft_isalpha(int c)
- c가 'a' ~ 'z' 'A' ~ 'Z' 안에 포함되는지 검시한다.
- alphabet이면 1리턴 아니면 0을 리턴한다.
---
### ft_isdigit
    int	ft_isdigit(int c)
- c가 '0' ~ '9' 안에 포함되는지 검사한다.
- 숫자이면 1, 아니면 0을 리턴한다.
---
### ft_isalnum
    int	ft_isalnum(int c)
- c가 숫자 or 알파벳인지를 검사한다.
- 숫자 나 알파벳이면 1, 아니면 0을 리턴한다.
---
### ft_isascii
    int	ft_isascii(int c)
- c가 아스키 넘버 안에 포함되는지 검사한다.
- 아스키 넘버이면 1, 아니면 0을 리턴한다.
---
### ft_isprint
    int	ft_isprint(int c)
- c가 출력 가능한 문자열인지를 검사한다.
- 출력 가능하면 1, 불가능하면 0을 리턴한다.
### ft_toupper
    int	ft_toupper(int c)
- c가 소문자인지를 검사를 하고, 소문자이면 대문자로 변환한다.
- 대문자로 변환된 c 를 리턴한다.
---
### ft_tolower
    int	ft_tolower(int c)
- c가 대문자인지를 검사 하고, 대문자이면 소문자로 변환한다.
- 소문자로 변환된 c를 리턴한다.
---

## Part.2
### ft_substr
    char	*ft_substr(char const *s, unsigned int start, size_t len)
- s 문자열을 start 인덱스부터 len 만큼 문자열을 자른 후 동적할당 된 새로운 문자열에 복사, 리턴
- 예외 1. s가 빈 문자열 -> null 리턴
- 예외 2. s문자열의 길이보다 start인덱스가 클 경우 -> 빈 문자열을 리턴한다.
- 예외 3. malloc 실패 시 -> null 리턴
---
### ft_strjoin
    char	*ft_strjoin(char const *s1, char const *s2)
- s1 문자열 뒤에 s2 문자열을 붙인 새로 문자열 ret를 만들어서 '\0'종료 후 리턴
- 예외 1. !s1 && !s2 -> null리턴
- 예외 2. !s1 -> s2를 복제하여 리턴한다.
- 예외 3. !s2 -> s1을 복제하여 리턴한다.
---
### ft_strtrim
    char	*ft_strtrim(char const *s1, char const *set)
- s1 문자열에서 처음과 끝에서 set 문자열을 제거 후 리턴한다.
- 예외 1. !s1 -> null 리턴
- 예외 2. !set -> s1을 복제하여 리턴한다.
- 예외 3. start >= end -> 빈 문자열을 리턴한다.<br>
문자열의 처음부터 set 문자열을 찾을때, 문자열의 끝까지 간 경우
---
### ft_split
    char	**ft_split(char const *s, char c)
- s문자열에서 c문자를 구분자로 사용하여 문자열을 나누어 리턴한다. 리턴값은 이중 포인터.
- 예외 1. !s -> null 리턴
- 예외 2. malloc error -> null 리턴
- 예외 3. 문자열 나누는 도중 malloc error -> 할당했던 것들을 모두 free한후 ret도 free해준다.
---
### ft_itoa
    char    *ft_itoa(int n)
- int형 숫자 n 을 받아서 문자열로 변환후 리턴한다.
- 예외 1. malloc error -> null 리턴
- 예외 2. 추후에 long long, unsigned int형 같은 다른 자료형이 들어왔을때, 오버플로우, 언더플로우가 일어날 수 있는 부분을 염두해 두어야 한다.
--- 
### ft_strmapi
    char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
- 함수 포인터 f를 받아서, s의 문자들을 각각 함수에 적용시켜 새로운 문자열을 리턴한다.
- 예외 1. !s || !f ->  null리턴
- 예외 2. malloc할당 실패시 -> null리턴
---
### ft_putchar_fd
    void	ft_putchar_fd(char c, int fd)
- file descriptor를 매개변수로 받아 file안에 문자를 작성한다.
- 예외 1. 전달받은 fd가 음수일 경우 -> return ;
---
### ft_putstr_fd
    void	ft_putstr_fd(char *s, int fd)
- file descriptor를 매개변수로 받아 file안에 s 문자열을 작성한다.
- 예외 1. !s || fd < 0 -> return ; 
---
### ft_putendl_fd
    void	ft_putendl_fd(char *s, int fd)
- file descriptor를 매개변수로 받아 file안에 s 문자열을 작성후 개행한다.
- 예외 1. !s || fd < 0 -> return ;
---
### ft_putnbr_fd
    void	ft_putnbr_fd(int n, int fd)
- file descriptor를 매개변수로 받아 file안에 숫자 n을 작성한다.
- 예외 1. fd < 0 -> return ;
- 예외 2. n이 INT_MIN인 경우
--- 
## Bonus
### ft_lstnew
    t_list		*ft_lstnew(void *content)
- 새로운 list를 만들고 구조체 항목들을 초기화한다.
- list->next : null / list->content : content 로 초기화.
- 예외 1. malloc 할당 실패시 null 리턴
---
### ft_lstadd_front
    void	ft_lstadd_front(t_list **lst, t_list *new)
- lst의 맨 앞에 new를 추가한다.
- 맨 앞에 있는 항목을 new -> next로 변경한다.
- *lst = new;

---
### ft_lstsize
    int	ft_lstsize(t_list *lst)
- lst의 처음 요소를 매개변수로 받아 list의 길이를 구한다.
---
### ft_lstlast
    t_list	*ft_lstlast(t_list *lst)
- list의 시작을 매개변수로 받아 list의 마지막 element를 리턴한다.
- 예외 1. !lst -> null 리턴
---
### ft_lstadd_back
    void	ft_lstadd_back(t_list **lst, t_list *new)
- list 의 첫 주소를 매개변수로 받아 new를 리스트의 마지막에 추가한다.
- 예외 1. !lst || !new -> return ;
- 예외 2. lst 가 비었을때 -> new를 첫 요소로 넣는다.
---
### ft_lstdelone
    void    ft_lstdelone(t_list *lst, void (*del)(void *))
- free될 리스트와, content를 지우는 함수(del)를 받아, content를 지우고, element를 free 한다.
- next는 free돼서는 안된다.
- 예외 1. !lst || !del -> return ;
---
### ft_lstclear
    void    ft_lstclear(t_list **lst, void (*del)(void *))
- lst의 주소를 받아, lst의 모든 요소를 del 과 free를 이용하여 free한다.
- 결과적으로 lst는 null롤 바뀌어야 한다.
- 예외 1. !lst || !del -> return ;
---
### ft_lstiter
    void    ft_lstiter(t_list *lst, void (*f)(void *))
- lst의 content 항목을 f 함수를 적용시켜라. 모든 lst가 적용되어야 한다.
- 예외 1. !lst -> return ;
---
### ft_lstmap
    t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
- lst의 모든 element를 f 함수를 적용시키고, 새로운 list를 만들어서 리턴해라.
- 새로운 리스트는 content에 f 함수를 적용시킨 결과이다.
- 예외 1. !lst -> null 리턴
---
