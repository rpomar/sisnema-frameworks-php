<?php

	require_once('classes/classe_bancodados.inc');

	$bd = new mysql('localhost', 'root');

	$bd->startTransaction();

	$houveErro = false;

	$bd->executaSQL("use cake;");

	$execRet = $bd->executaSQL("INSERT INTO articles (title, body) VALUES ('Aluno 01', 'Rafael Pomar');");

	if(!$execRet){
		$houveErro = true;
	}
	$execRet = $bd->executaSQL("INSERT INTO articles (title, body) VALUES ('Aluno 02', 'Carlos');");
	
	if(!$execRet){
		$houveErro = true;
	}

	$execRet = $bd->executaSQL("INSERT INTO articles (title, body) VALUES ('Aluno 03', 'Rafael Garcia');");

	if(!$execRet){
		$houveErro = true;
	}


	$execRet = $bd->executaSQL( "INSERT INTO articles (title, body) VALUES ('Aluno 04', 'Deise');");

	if(!$execRet){
		$houveErro = true;
	}

	if($houveErro){

		$bd->ROLLBACK();

	}else{
		
		$bd->commit();
	}

	
