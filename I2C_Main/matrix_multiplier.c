//void get_matrices(u8*** matrix1, u8*** matrix2){
//	u8 read_char;
//	u8 temp[10];
//	u8 temp_length = 0;
//	USART_send_string("Enter First Matrix...\n");
//	for(u8 i=0; i<2; i++){
//		for(u8 j=0; j<2; j++){
//			read_char = USART_recieve_char();
//			if(read_char == '['){
//				j--;
//			}else if(read_char != ',' && read_char != ']'){
//				temp[temp_length] = read_char;
//				temp_length++;
//				j--;
//			}else if(read_char == ']' || read_char == ','){
//				temp[temp_length] = '\0';
//				matrix1[i][j] = (u8*) malloc(temp_length + 1);
//				strcpy(matrix1[i][j], temp);
//				temp_length = 0;
//				strcpy(temp, "");
//			}
//		}
//	}
//	USART_send_string("Enter Second Matrix...\n");
//	for(u8 i=0; i<2; i++){
//		for(u8 j=0; j<2; j++){
//			read_char = USART_recieve_char();
//			if(read_char == '[' || read_char == '\n'){
//				j--;
//			}else if(read_char != ',' && read_char != ']'){
//				temp[temp_length] = read_char;
//				temp_length++;
//				j--;
//			}else if(read_char == ']' || read_char == ','){
//				temp[temp_length] = '\0';
//				matrix2[i][j] = (u8*) malloc(temp_length + 1);
//				strcpy(matrix2[i][j], temp);
//				temp_length = 0;
//				strcpy(temp, "");
//			}
//		}
//	}
//}
//
//
//
//void show_matrices(u8*** matrix1, u8*** matrix2){
//	USART_send_string("Recieved Matrices:\n");
//	USART_send_char('[');
//	USART_send_string(matrix1[0][0]);
//	USART_send_char(',');
//	USART_send_string(matrix1[0][1]);
//	USART_send_char(',');
//	USART_send_string(matrix1[1][0]);
//	USART_send_char(',');
//	USART_send_string(matrix1[1][1]);
//	USART_send_char(']');
//	USART_send_char('\n');
//	USART_send_char('[');
//	USART_send_string(matrix2[0][0]);
//	USART_send_char(',');
//	USART_send_string(matrix2[0][1]);
//	USART_send_char(',');
//	USART_send_string(matrix2[1][0]);
//	USART_send_char(',');
//	USART_send_string(matrix2[1][1]);
//	USART_send_char(']');
//}
