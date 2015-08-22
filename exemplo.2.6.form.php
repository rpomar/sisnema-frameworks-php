<form method="POST" action="exemplo.2.6.editar.php">

	<input type="hidden" name="id" value="<?php echo $resultado[$posicao]['id'] ?>" />
	<input type="hidden" name="posicao" value="<?php echo $posicao ?>" />
	<fieldset>
		<legend>Dados do registro</legend>
		<dl>
			<dt> 
				<label for="title">Titulo</label> 
			</dt>
			<dd> 
				<input name="title" id="title" value="<?php echo $resultado[$posicao]['title'] ?>" placeholder="seu titulo aqui" /> 
			</dd>
			<dt>
				<label for="body">Conteudo</label> 
			</dt>
			<dd> 
				<input name="body" id="body" value="<?php echo $resultado[$posicao]['body'] ?>"  placeholder="cara de quem tem conteudo"  /> 
			</dd>
			<button type="submit">Enviar</button>
		</dl>
	</fieldset>
</form>