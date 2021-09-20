; ** Implementacion de la serie Fibonacci utilizando printf y scanf **
;   -Autores: 
;   David Alejandro Perez Rico - 320753
;   Jesica Yamile Salcido Cadena -  329575  
includelib libcmt.lib
includelib libucrt.lib
includelib legacy_stdio_definitions.lib
extern printf:proc
extern scanf:proc
.data
    aux DQ 1
    fib DQ 0
    iter DQ 1
    pos DQ 0
    msg1 DB "Ingrese termino a buscar de fibomacci: ",0
    msg2 DB "El numero es: %d -> Serie fib: ",0
    msg3 DB "%d ",0
    fmt1 DB "%d",0
.code
main proc
    and rsp,-16

    ;; Imprimimos el mensaje
    lea RCX,msg1
    sub rsp,32
    call printf
    add rsp,32

    MOV RCX,0
    MOV RDX,0

    ;; Pedimos el termino fibonacci
    lea RDX,pos
    lea RCX,fmt1
    sub rsp,32
    call scanf
    add rsp,32

    MOV RCX,0
    MOV RDX,0
    ;; Verificamos que el numero se ingreso bien
    mov RDX,pos
    lea RCX,msg2
    sub rsp,32
    call printf
    add rsp,32

    MOV RSI,pos

    Ciclo1: 
        cmp iter, RSI
        ja exit

        mov RCX,0

        ; Imprimimos 
        mov RDX,fib
        lea RCX,msg3
        sub rsp,32
        call printf
        add rsp,32

        ; Se calcula el siguiente numero de la serie fibonacci
        mov RAX, fib
        add aux, RAX
        mov RBX, aux
        sub RBX, fib
        mov fib, RBX

        inc iter
    loop Ciclo1
    exit:

main endp
end
;ml64 /Zi /Zd /Zf tercer.asm /link /subsystem:console /debug:full