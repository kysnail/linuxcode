import java.util.List;
import java.util.ArrayList;

public class StudentList {

    // 定义 getStudents() 方法，使用 List 集合保存学生信息，返回集合，在主方法中遍历该集合，输出信息。
    private List<String> getStudent() {
        List<String> list = new ArrayList<String>();
        // 这里这种写法很有意思，写成了 `csv` 的格式，这样便于进行数据处理，同样也不需要将每个字段分开写，值得记忆。
        list.add("李哥,男,1984-10-6");
        list.add("小陈,女,1982-5-10");
        list.add("小刘,男,1983-10-5");
        list.add("小张,男,1981-1-1");
        list.add("小董,男,1980-7-19");
        list.add("小吕,男,1984-11-3");

        return list;
    }
    public static void main(String[] args) {
        StudentList slist = new StudentList();
        List list = slist.getStudent();

        for (int i = 0; i < list.size(); i++) {
            String str = (String)list.get(i);
            String[] sList = str.split(",");
            System.out.println("姓名： " + sList[0] + "， 性别： " + sList[1] + "， 出生日期： " + sList[2]);
        }
    }
}
