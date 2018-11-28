lexer grammar C1Lexer;

tokens {
	Comma,
	SemiColon,
	Assign,
	LeftBracket,
	RightBracket,
	LeftBrace,
	RightBrace,
	LeftParen,
	RightParen,
	If,
	Else,
	While,
	Const,
	Equal,
	NonEqual,
	Less,
	Greater,
	LessEqual,
	GreaterEqual,
	Plus,
	Minus,
	Multiply,
	Divide,
	Modulo,

	Int,
	Float,
	Void,

	Identifier,
	IntConst,
	FloatConst
}

Unformal_annotation:
	'/' ('\\' ('\n' | '\r\n'))*? '/' (
		('\n' | EOF | '\r\n')
		| (.*? ~'\\' ('\n' | EOF | '\r\n'))
	) -> skip;
//Check: '//'.*?'\n';
Formal_annotation: '/*' .*? ('*/' | EOF) -> skip;

LeftParen: '(';
RightParen: ')';
LeftBrace: '{';
RightBrace: '}';
LeftBracket: '[';
RightBracket: ']';
Equal: '==';
NonEqual: '!=';
Greater: '>';
Less: '<';
LessEqual: '<=';
GreaterEqual: '>=';
Assign: '=';
SemiColon: ';';
Comma: ',';

If: 'if';
Else: 'else';
While: 'while';
Const: 'const';

Int: 'int';
Float: 'float';
Void: 'void';

Identifier: [a-zA-Z_][0-9a-zA-Z_]*;
IntConst:
	[1-9][0-9]*
	| '0' [0-7]*
	| ('0x' | '0X') [0-9a-fA-F]*;
FloatConst:
	([0-9]* '.' [0-9]+ | [0-9]+ '.') ([eE][+-]? [0-9]+)?
	| [0-9]+ [eE][+-]? [0-9]+
	| '0' [xX](
		([0-9a-fA-F]* '.' [0-9a-fA-F]+ | [0-9a-fA-F]+ '.') (
			[pP][+-]? [0-9a-fA-F]+
		)?
		| [0-9a-fA-F]+ [pP][+-]? [0-9a-fA-F]+
	);

Plus: '+';
Minus: '-';
Multiply: '*';
Divide: '/';
Modulo: '%';

WhiteSpace: [ \t\r\n]+ -> skip;
Line_break: ('\\\n' | '\\\r\n') -> skip; 