<?php

	require_once('classes/classe_bancodados.inc');

	$bd = new mysql('localhost', 'root', '', 'cake');
	$bd->insert(
			'articles',
	 		array(
	 			'title', 'body'
	 			),
	 		array(
	 			'aluno 06', 'fanfarrao','123123123'
	 			)
	  );
