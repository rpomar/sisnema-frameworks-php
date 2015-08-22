<?php

require_once('classes/classe_bancodados.inc');

$bd = new mysql('localhost', 'root', '', 'cake');

$resultado = $bd->find('articles', 'title', 'aluno', true);

$posicao = isset($_GET['posicao']) ? $_GET['posicao'] : 0 ;

if(isset($_GET['posicao'])){

	$resultado = array( $posicao => $bd->navega($posicao));
}

if(isset($_GET['acao']) && $_GET['acao'] == "editar"){

	include('exemplo.2.6.form.php');

	} else {

?>
<table border=1>
	<thead>
		<tr>
			<td>id</td>
			<td>title</td>
			<td>body</td>
			<td>editar</td>
			<td>deletar</td>
		</tr>
	</thead>
	<tbody>
<?php foreach( $resultado as $pos => $item ){ ?>

		<tr>
			<td><?= $item['id'] ?></td>
			<td><?= $item['title'] ?></td>
			<td><?= $item['body'] ?></td>
			<td>
				<a href="?posicao=<?= $pos ?>&acao=editar">editar</a>
			</td>
			<td>
				<a href="?posicao=<?= $pos ?>&acao=deletar">deletar</a>
			</td>
		</tr>

<?php } ?>
	</tbody>
</table>

<?php } ?>