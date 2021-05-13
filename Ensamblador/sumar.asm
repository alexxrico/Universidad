; * Variable a debuggear es "SUMA"
;   -Autores: 
;   David Alejandro Perez Rico - 320753
;   Jesica Yamile Salcido Cadena -  329575
.data
    var1 DQ 1
    var2 DQ 2
    var3 DQ 3
    var4 DQ 4
    var5 DQ 5
    var6 DQ 6
    var7 DQ 7
    var8 DQ 8
    var9 DQ 9
    SUMA DQ 0
.code
main proc
    push var9
    push var8
    push var7
    push var6
    push var5

    mov R9, var4
    mov R8, var3
    mov RDX, var2
    mov RCX, var1

    SUB RSP, 32
    call Funcion1
    ADD RSP, 32
    ret
main endp
Funcion1 proc
    mov SUMA, 2 ; Le ponemos el valor de 2 para multipicarlo despues
    
    mov RAX, SUMA
    ADD RAX,RCX ; Resultado + Var1

    ADD RAX, SUMA
    ADD RAX,RDX ; Resultado + Var2

    ADD RAX, SUMA
    ADD RAX,R8  ; Resultado + Var3

    ADD RAX, SUMA
    ADD RAX,R9  ; Resultado + Var4

    ADD RAX, SUMA
    ADD RAX, qword ptr[RSP+40] ; Resultado + var5

    ADD RAX, SUMA
    ADD RAX, qword ptr[RSP+48] ; Resultado + Var6

    ADD RAX, SUMA
    ADD RAX, qword ptr[RSP+56] ; Resultado + Var7

    ADD RAX, SUMA
    ADD RAX, qword ptr[RSP+64] ; Resultado + Var8

    ADD RAX, SUMA
    ADD RAX, qword ptr[RSP+72] ; Resultado + Var9

    mul SUMA      ; Lo del registro RAX lo multiplicamos por SUMA que vale 2

    mov SUMA, RAX ; Guardamos el reultado de la multiplicacion (RAX) en SUMA
    ; Resultado en decimal es "126", pero se muestra como hexadecimal como "7e"
Funcion1 endp
end
; ml64 /Zi /Zd /Zf sumar.asm /link /subsystem:console /entry:main /debug:full
; .sympath svr*
; .reload
; bu sumar!main