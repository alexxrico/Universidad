; ** Implementacion de la serie Fibonacci utilizando arreglos y apuntadores **
;   -Autores: 
;   David Alejandro Perez Rico - 320753
;   Jesica Yamile Salcido Cadena -  329575  
.data
    aux DB 1
    fib DB 0
    Iter1 DB 0
    Iter2 DB 0
    array DB 0, 1, 2, 3, 4, 5, 6, 7
    auxi DB 0 
.code
main proc
    mov RBX, 0
    lea RBX, array

    mov AH, 0

    Ciclo1: 
        cmp Iter1, 7
        ja Ciclo2

        mov AL, fib
        mov byte ptr[RBX], AL

        mov AH, fib
        add aux, AH
        mov AL, aux
        sub AL, fib
        mov fib, AL

        inc RBX
        inc Iter1
    loop Ciclo1

    Ciclo2:
        cmp Iter2, 7
        ja exit

        mov AL, byte ptr[RBX]
        mov auxi, AL

        dec RBX
        inc Iter2
    loop Ciclo2
    
    exit:
main endp
end
;ml64 /Zi /Zd /Zf fibonacci.asm /link /subsystem:console /entry:main /debug:full
;.sympath svr*