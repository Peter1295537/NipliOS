#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xmlstring.h>

xmlDocPtr readDoc(const char* filename){
	xmlDocPtr doc;
	doc = xmlParseFile(filename);

	if (doc == NULL){
		fprintf(stderr, "Document %s failed to parse", filename);
		return NULL;
	}
	
	return doc;

}

void main(){

	xmlDocPtr doc;
	xmlNodePtr node;
	xmlNodePtr current_node;
	const char* filename = "process_template.xml";
	
	doc = readDoc(filename);
	
	if (doc == NULL){
		fprintf(stderr, "Document %s failed to parse", filename);
		return;
	}

	node = xmlDocGetRootElement(doc);
	current_node=node->children;
	current_node=current_node->next;
	char* content = xmlNodeGetContent(current_node);
	printf("%s \n",(const char*)node->name);
	printf("%s",content);

}
