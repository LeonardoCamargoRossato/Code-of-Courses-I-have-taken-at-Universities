Program sistema_eqs_lineares
implicit none

!	integer :: i,j,k,n
!	parameter (n=3) !Macro
!	Real :: x(n),c

	integer n

	Real  a(3,3) /3.0d0, 2.0d0 ,1.0d0, 2.0d0, -3.0d0, 1.0d0, 4.0d0, 1.0d0 , 2.0d0/
	Real  b(3) /4.0d0, 2.0d0 , 3.0d0 /

!	n = 3
	
!	n = 2
!	Real  a(2,2) /3.0d0, 2.0d0 ,1.0d0, 2.0d0/
!	Real  b(2) /4.0d0, 2.0d0 /

!Aqui escreve as eq na tela

Write(*,*)
Write(*,*) '############################################'
Write(*,*) 'Aqui chama a SubRoutine: Printa_Sistema(a,b)'
Write(*,*) '############################################'
Write(*,*)

Call Printa_Sistema(a,b,3)


Write(*,*)
Write(*,*) '############################################'
Write(*,*) 'Aqui chama a SubRoutine: Resolve_Sistema(a,b)'
Write(*,*) '############################################'
Write(*,*)

Call Resolve_Sistema(a,b,3)

CONTAINS  !Só dá pra escrever Functions and SubRoutines dps do CONTAINS


!##########################################################
! F U N Ç O E S   E X T E R N A S  
!##########################################################

SUBROUTINE Printa_Sistema(a,b,n)
	implicit none
	
	
	integer :: i,j,n2
	n2 = n
!	write(*,*) n2, n
	REAL, intent(out) :: a(n2,n2)
	REAL, intent(out) :: b(n2)

!	Real  a(n2,n2)
!	Real  b(n2)

	
	do i=1, n2
		write(*,*) (a(i,j),j(=1,n2))
		Write(*,*)
	end do

END SUBROUTINE Printa_Sistema


SUBROUTINE Resolve_Sistema(a,b,n)
	implicit none
	
	
	integer :: i,j,k,n2
	n2 = n
	Real :: c


	REAL, intent(out) :: x(n2)

	REAL, intent(out) :: a(n2,n2)
	REAL, intent(out) :: b(n2)

	
!	Real  a(n2,n2)
!	Real  b(n2)
	
	
	
!Função 1
	do k=1, n2-1
		do i=k+1,n2
		c = a(i,k) / a(k,k)
		a(i,k) = 0.0
		b(i) = b(i) - c*b(k)
		do j=k+1,n
		a(i,j) = a(i,j)-c*a(k,j)
		end do
	end do
	end do


!Função 2
	x(n2) = b(n2) / a(n2,n2)
	
	do i=n2-1,1,-1
	c = (0,0)
		do j=i+1,n2
		c = c + a(i,j)*x(j)
		end do
	x(i) = (b(i) - c) / a(i,i)
	end do

Write(*,*)
Write(*,*) '############################################'
Write(*,*) 'Aqui Mostra a Solução do Sistema'
Write(*,*) '############################################'
Write(*,*)

!write(*,*) (x(i), i(1,n2))

	write(*,*) 'x(1) =', x(1), 'x(2) =', x(2),'x(3) =', x(3)
	
	
	
!	do i=1, n2
!		write(*,*) (x(i), i(1,n)
!	end do
	
END SUBROUTINE Resolve_Sistema

end program
