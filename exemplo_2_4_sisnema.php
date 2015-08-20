<?php 

require_once('classes/classe_bancodados.inc');


$bd = new mysql('localhost', 'root', '', 'cake');

$insert = $bd->insert(
	'articles', 
	array(
		'title', 'body'
		), 
	array(
		'aluno 10', 'fanfarrao novamente'
		),

	array(
		'aluno 20', 'fanfarrao colado'
		),

	array(
		'aluno 30', 'fanfarrao colado'
		)


	);

if($insert){
	echo "inserido com sucesso";
} else {
	echo "no, no, no, no";
}