#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char* get_class(char* lexeme){
	int len = strlen(lexeme);
	
	//predeclared
	if(!strcmp(lexeme,"boolean") || !strcmp(lexeme, "real")||!strcmp(lexeme, "true")
	|| !strcmp(lexeme,"integer")|| !strcmp(lexeme, "char" )||!strcmp(lexeme, "false")
	|| !strcmp(lexeme, "string")|| !strcmp(lexeme, "read")||!strcmp(lexeme, "readln")
	|| !strcmp(lexeme, "write")|| !strcmp(lexeme, "writeln") )
		return "Predeclared";
	
	//reserved
	if(!strcmp(lexeme, "program")|| !strcmp(lexeme, "and")|| !strcmp(lexeme, "array")
	|| !strcmp(lexeme, "for")|| !strcmp(lexeme,"while" )|| !strcmp(lexeme, "begin" )
	|| !strcmp(lexeme, "or")|| !strcmp(lexeme, "of") || !strcmp(lexeme, "to")
	|| !strcmp(lexeme, "do")|| !strcmp(lexeme, "end") || !strcmp(lexeme, "not")
	|| !strcmp(lexeme, "if") || !strcmp(lexeme, "downto")|| !strcmp(lexeme, "mod")
	|| !strcmp(lexeme, "function") || !strcmp(lexeme, "var")|| !strcmp(lexeme, "then")
	|| !strcmp(lexeme, "repeat") || !strcmp(lexeme, "div") || !strcmp(lexeme, "procedure")
	|| !strcmp(lexeme, "const") || !strcmp(lexeme, "else")|| !strcmp(lexeme, "until")
	|| !strcmp(lexeme, "return"))
		return "Reserved";	
		
	//identifiers
	if(isalpha(lexeme[0])){
		if(isalnum(lexeme))
			return "identifier";
	}
		
	//arithmetic operators
	else if(!strcmp(lexeme, "*") || !strcmp(lexeme, "/") || !strcmp(lexeme, "+")
	|| !strcmp(lexeme, "-"))
		return "Arithmetic";
	
	//relational operators
	else if(!strcmp(lexeme, "=" ) || !strcmp(lexeme, "<>") || !strcmp(lexeme, "<")
	|| !strcmp(lexeme, ">") || !strcmp(lexeme, "<=") || !strcmp(lexeme, ">="))
		return "Relational";
	
	//single assignment :=
	else if(!strcmp(lexeme, ":="))
		return "Assignment";
	
	//semicolon
	else if(!strcmp(lexeme, ";"))
		return "Semicolon";
	
	//colon
	else if(!strcmp(lexeme, ":"))
		return "Colon";
		
	//comma
	else if(!strcmp(lexeme, ","))
		return "Comma";
		
	//Real and Integer
	bool isDecimal;
	if(isdigit(lexeme[0])){
		while(len--){ 
		if(lexeme[len]=='.') 
		{ 
			isDecimal= true; 
			break; 
		} 
	} 
	if(isDecimal) 
		return "Real"; 
	else 
		return "Integer";
	} 
	
	
	//Comment
}

int main(){
	char* lexeme_class = get_class("iam2");
	printf(lexeme_class);
	return 0;
}
