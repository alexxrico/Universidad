; implementar entrada y salida de datos en lenguaje ensamblador
; codigo por el equipo "Los taquicardios": Luis Izquierdo y Maria Fernanda Mata
; trabajamos con la serie fibonacci
includelib libcmt.lib
includelib libucrt.lib
includelib legacy_stdio_definitions.lib
extrn printf:proc
extrn scanf:proc
.data
    number DQ 0
    iterator DQ 1
    first DQ 0
    second DQ 1
    current DQ 0
    msg1 DB " Digame un numero para la serie fibonacci: ", 0
    msg2 DB " Esta es la serie para el numero %d: ", 0
    msg3 DB "%d ", 0
    fmt1 DB "%d", 0
.code
main proc
    and rsp, -16
    
    mov RCX, 0
    mov RDX, 0
    
    ; "Digame un numero para la serie fibonacci: "
    lea RCX, msg1
    sub rsp, 32
    call printf
    add rsp, 32

    mov RCX, 0
    mov RDX, 0
    
    ; instrucion que lee el numero
    lea RDX, number
    lea RCX, fmt1
    sub rsp, 32
    call scanf
    add rsp, 32

    mov RCX, 0
    mov RDX, 0
    mov DL, 0

    ; "Esta es la serie para el numero %d"
    mov RDX, number
    lea RCX, msg2
    sub rsp, 32
    call printf
    add rsp, 32
    
    mov RCX, 0
    mov RDX, 0
    mov DL, 0

    mov RBX, number; AL sera el iterador
    frootLoop: 
        cmp iterator, RBX
        ja exit; si no se cumple (iterator <= RAX) se termina el loop

        ; se muestra cada numero
            mov RDX, first
            lea RCX, msg3
            sub rsp, 32
            call printf
            add rsp, 32

        mov RAX, 0
        add RAX, first
        add RAX, second
        mov current, RAX; current = first + second

        mov RAX, 0
        mov RAX, second
        mov first, RAX; first = second

        mov RAX, 0
        mov RAX, current
        mov second, RAX; second = current
    
        inc iterator
    loop frootLoop
    
    exit:
main endp
end
;ml64 /Zi /Zd /Zf entrada.asm /link /subsystem:console 