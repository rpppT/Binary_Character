

import java.util.*;

 
public class Binary_Test_1{
	private String args;
	private ArrayList<String> list;
	private char [] array;
	private String [] decode_array;
	private String full_Binary;
	
	public Binary_Test_1(String args, ArrayList<String> list){		
		this.args = args;
		this.list = list;
		this.array = new char[args.length()];
		this.decode_array = new String[args.length()];
		this.full_Binary = "";
	}
	
	public void Convert_String() {
		int i, len;
		String temp;
		
		for(i=0; i<args.length(); i++) {
			array[i] = args.charAt(i);
		}

		
		for(i=0; i<array.length; i++) {
			temp=Integer.toBinaryString(array[i]);
		
			if(temp.length()<16) {
				len = 16-temp.length();
				for(int j=1; j<=len; j++) {
					temp = "0"+ temp;
				}
			}
			list.add(temp);
			
			this.full_Binary += temp;
		}
		
		System.out.println("Full Binary : "+this.full_Binary);
		Decode_String();
	}
	public void Decode_String() {
		int i, index;
		int save_binary=0;
		int max = 0;
		index  = 0;
	
		
		array = new char[args.length()];
		
		for(i=0; i<this.decode_array.length; i++) {
			decode_array[i] = full_Binary.substring(index, index+16);
			index += 16;
		}
		System.out.println(Arrays.toString(decode_array));
		for(i=0; i<decode_array.length; i++) {
			for(int j = 0; j<decode_array[i].length(); j++) {
				if(decode_array[i].charAt(j)=='1') {
					max = 15;
					max -= j;
					System.out.print(save_binary+" + ");
					save_binary += 1 << max;
					System.out.println((1<<max)+" = "+save_binary);
				}
			}
			System.out.println("============index["+i+"]==============");
			array[i] = (char)save_binary;
			save_binary = 0;
		}
		System.out.println(array);
	}
	public static void main(String[] args) {
		String _str_args = "";
		int i;
		
		for(i=0; i<args.length; i++)
			_str_args += args[i];
		
		new Binary_Test_1(_str_args,new ArrayList<String>()).Convert_String();
	}
}


