<?php 
require_once('classes/classe_bancodados.inc');


$bd = new mysql('localhost', 'root');


$bd->startTransaction();

$houveErro = false;

$bd->executaSQL('use cake;');


$execRet = $bd->executaSQL(" insert into articles(title, body) value ('aluno 01', 'Rafael Pomar');");

if(!$execRet){
	$houveErro = true;
}

$execRet = $bd->executaSQL(" insert into articles(title, body) value ('aluno 02', 'Carlos');");

if(!$execRet){
	$houveErro = true;
}

$execRet = $bd->executaSQL(" insert into articles(title, body) value ('aluno 03', 'Delegado Garcia');");


if(!$execRet){
	$houveErro = true;
}

$execRet = $bd->executaSQL(" insert into articles(title, body) value ('aluno 04', 'Deise ai ai ai');");

if(!$execRet){
	$houveErro = true;
}

if($houveErro){
	echo "houve um erro, estamos voltando, fique calmo";
	$bd->ROLLBACK();
} else {
	echo "sucesso, magrão. vamos gravar";
	$bd->commit();
}


