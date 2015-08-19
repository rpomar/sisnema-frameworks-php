<?php

	require_once ('classes\classe_bancodados.inc');


	//class BD extends BancoDados{};


	$bd = new mysql();

	//$conn = $bd->GetConn();

	$articles = $bd->executaSQL("SELECT * FROM cake.articles");

	//var_dump($articles);
	//die;

	$line = '';

	while ($obj = $articles->fetch_object()){
		$line.=$obj->id;
		$line.=$obj->title;
		$line.=$obj->body;
		$line.="<br>";

	}

	echo $line;
	


	