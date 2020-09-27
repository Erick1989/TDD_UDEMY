node{
	stage("BUILD"){
		checkout scm
		dir("GPIO_TEST"){
		bat label: '', script: 'echo %PATH%'
		bat "make"
		}
		}
	stage("TEST"){
		echo 'HELLO TEST'
	}
}