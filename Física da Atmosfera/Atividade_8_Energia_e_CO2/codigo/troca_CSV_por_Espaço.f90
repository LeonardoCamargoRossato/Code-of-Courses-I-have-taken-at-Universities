PROGRAM vazoes

    IMPLICIT NONE

    INTEGER :: i

    ! A variavel status verifica se houve 
    ! algum erro ao abrir o arquivo
    INTEGER :: status = 0

    ! Contador de posições de campos e número de campos
    INTEGER :: posicao_campo = 0, campos = 0

    ! Aloca espaco para leitura de uma linha de texto
    CHARACTER*2048 :: linha_texto   !50.000 tinha q ser

    ! Aloca espaço para um registro do banco de dados (111 campos)
    CHARACTER*32, DIMENSION(111) :: dados

    ! Abre o arquivo
    OPEN(UNIT=15, IOSTAT=status, FILE='dados_SM_from_324_2013_to_348_2014.txt', STATUS='OLD')

    ! Verifica se houve erro ao abrir o arquivo
    IF (status .GT. 0) THEN
        WRITE(*,*) "Erro ao abrir o arquivo!"
        ! Finaliza a execução se houve erro
        STOP
    ENDIF

    ! Looping de leitura do arquivo
    DO
        ! Lê uma linha completa (um registro)
        READ(15, '(A)', IOSTAT=status) linha_texto

        ! Verifica se chegou no final do arquivo...
        IF (status .LT. 0) THEN
            ! ...e sai do looping se finalizou
            EXIT
        ENDIF

        ! Separa os campos utilizando o ';' como delimitador
        posicao_campo = 1
        campos = 1

        DO i=1,LEN(linha_texto)
            ! se encontrar o ';'...
            IF (linha_texto(i:i) == ';') THEN                
                ! ...adiciona o campo no array 'dados'
                dados(campos) = linha_texto(posicao_campo:i-1)
                campos = campos + 1
                ! marca a posição do último ';' encontrado
                posicao_campo = i+1
            ENDIF            
        ENDDO

        ! Imprime cada campo em formato texto na saída padrão
        WRITE(*,*) 'Inicio'
        DO i=1,campos-1            
            WRITE(50000,*) dados(i)
        ENDDO
        WRITE(*,*) 'Fim.'

    END DO
		
		write(*,*)
		print*, 'end'
		
    ! Fecha o arquivo    
    CLOSE(UNIT=15, IOSTAT=status)    
    ! Verifica se houve erro ao fechar o arquivo    
    IF (status .GT. 0) THEN
        WRITE(*,*) "Erro ao fechar o arquivo!"
        ! Finaliza a execução se houve erro
        STOP
    ENDIF

END PROGRAM vazoes
