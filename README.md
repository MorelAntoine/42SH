# 42sh

Own shell base on TCSH made in C

    Dev period: 18 may 2016 - 05 june 2016

Functionalities
=============
* Simple exec
* pipe |
* Redirections >, >> and <
* Binary operations &&, ||
* Simple quote and double quotes
* Builtins (cd, echo, exit)
* Env variables $
* History
* Job control

Exemple
=======

        ?> cat < Makefile | grep "main" | cat -e && echo $USER : success >> result
        SRC		=		src/main.c					\$
        				src/system/mainloop.c				\$
        ?> ls result 
        result
        ?> cat result
        antoine : success

Made By
=======

> Antoine MOREL

> Baptiste MAIRESSE

> Dylan DEU

> Geoffrey DAVRIL
