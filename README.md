# **GNL - 42 PROJECT**
*This activity has been created as part of the 42 curriculum by bdecourt*

---

## **Description**

We have to recreate from scratch the `get_next_line` function, which reads a file descriptor line by line. Each call to the function returns the next line of the file, including the `\n` character. We have to handle multiple file descriptors and manage a static buffer correctly.

---

## **Instructions**

Clone the project using git clone :
```bash
git clone <repo_url>
```

## **Resources**

I used AI as a teacher to get some help with some errors and to get better knowledge of static variables and file descriptors. I also used documentation like :

- [File Descriptor — Wikipedia](https://en.wikipedia.org/wiki/File_descriptor)
- [Static Variables in C](https://en.wikipedia.org/wiki/Static_variable)

---

## **What's inside the project ?**

| File | Role |
|---|---|
| `get_next_line.c` | Main file — core logic of the function |
| `get_next_line_utils.c` | Helper functions (ft_strlen, ft_strjoin, etc.) |
| `get_next_line.h` | Header file |
