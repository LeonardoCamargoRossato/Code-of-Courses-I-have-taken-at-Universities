Program Cria_Tabela
	Implicit none
	Integer :: i,n
	Real*8 :: T1(4096),U1(4096),C1(4096),X_max1(4096),X_min1(4096),F1(4096),S1(4096),m_max1(4096),m_min1(4096),m4_1(4096)
	Real*8 :: T2(4096),U2(4096),C2(4096),X_max2(4096),X_min2(4096),F2(4096),S2(4096),m_max2(4096),m_min2(4096),m4_2(4096)
	Real*8 :: T3(4096),U3(4096),C3(4096),X_max3(4096),X_min3(4096),F3(4096),S3(4096),m_max3(4096),m_min3(4096),m4_3(4096)
	Real*8 :: T4(4096),U4(4096),C4(4096),X_max4(4096),X_min4(4096),F4(4096),S4(4096),m_max4(4096),m_min4(4096),m4_4(4096)
	Real*8 :: T5(4096),U5(4096),C5(4096),X_max5(4096),X_min5(4096),F5(4096),S5(4096),m_max5(4096),m_min5(4096),m4_5(4096)
	Real*8 :: T6(4096),U6(4096),C6(4096),X_max6(4096),X_min6(4096),F6(4096),S6(4096),m_max6(4096),m_min6(4096),m4_6(4096)
	Real*8 :: T7(4096),U7(4096),C7(4096),X_max7(4096),X_min7(4096),F7(4096),S7(4096),m_max7(4096),m_min7(4096),m4_7(4096)
	Real*8 :: T8(4096),U8(4096),C8(4096),X_max8(4096),X_min8(4096),F8(4096),S8(4096),m_max8(4096),m_min8(4096),m4_8(4096)

	Integer in,out
	in=1
	out=2
	n = 3441
	
	open(in,file='1fort.12000',status='old')
	do i=1,n
		read(in,*) T1(i),m_max1(i),m_min1(i),U1(i),F1(i),S1(i),m4_1(i)
	end do
	
	open(in,file='2fort.12000',status='old')
	do i=1,n
		read(in,*) T2(i),m_max2(i),m_min2(i),U2(i),F2(i),S2(i),m4_2(i)
	end do
	
	open(in,file='3fort.12000',status='old')
	do i=1,n
		read(in,*) T3(i),m_max3(i),m_min3(i),U3(i),F3(i),S3(i),m4_3(i)
	end do
	
	open(in,file='4fort.12000',status='old')
	do i=1,n
		read(in,*) T4(i),m_max4(i),m_min4(i),U4(i),F4(i),S4(i),m4_4(i)
	end do
	
	open(in,file='5fort.12000',status='old')
	do i=1,n
		read(in,*) T5(i),m_max5(i),m_min5(i),U5(i),F5(i),S5(i),m4_5(i)
	end do
	
	open(in,file='6fort.12000',status='old')
	do i=1,n
		read(in,*) T6(i),m_max6(i),m_min6(i),U6(i),F6(i),S6(i),m4_6(i)
	end do
	
	open(in,file='7fort.12000',status='old')
	do i=1,n
		read(in,*) T7(i),m_max7(i),m_min7(i),U7(i),F7(i),S7(i),m4_7(i)
	end do
	
	open(in,file='8fort.12000',status='old')
	do i=1,n
		read(in,*) T8(i),m_max8(i),m_min8(i),U8(i),F8(i),S8(i),m4_8(i)
	end do
!------------------------------------------	
	open(out,file='mag',status='unknown')
	do i=1,n
		write(out,*) T1(i),m_max1(i),m_max2(i),m_max3(i),m_max4(i), &
			m_max5(i),m_max6(i),m_max7(i),m_max8(i), &
			m_min1(i),m_min2(i),m_min3(i),m_min4(i), &
			m_min5(i),m_min6(i),m_min7(i),m_min8(i), &
			m4_1(i),m4_2(i),m4_3(i),m4_4(i), &
			m4_5(i),m4_6(i),m4_7(i),m4_8(i)
	end do
	
End Program
