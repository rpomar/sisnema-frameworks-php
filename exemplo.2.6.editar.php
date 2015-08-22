<?php

require_once('classes/classe_bancodados.inc');

$bd = new mysql('localhost', 'root', '', 'cake');

$id = $_POST['id'];

$infoParaAtualizar = array(
	'title' => $_POST['title'],
	'body' => $_POST['body']
	);

$resultado = $bd->atualizar('articles', 'id', $id, $infoParaAtualizar);


// @TODO: verificar o status, se foi atualizado com sucesso
// @TODO: pegar o $_POST['posicao']
// redirecionar para o registro correspondente 'exemplo.2.6.php?posicao=' 
// @DESAFIO: implementar uma forma de passar a mensagem de sucesso ou erro (estudar SESSION)

var_dump($resultado);
