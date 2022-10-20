#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_wuk_ndkdemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_wuk_ndkdemo_MainActivity_callPlusMethod(JNIEnv *env, jobject jobj) {
    // 通过jobject获取到jclass
    jclass j_clzz = env->GetObjectClass(jobj);
    //通过jclass对象获取jmethodID
    jmethodID methodID = env->GetMethodID(j_clzz, "onPlus", "(II)I");
    //调用onPlus方法
    return env->CallIntMethod(jobj, methodID, 3, 2);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_wuk_ndkdemo_MainActivity_changeName(JNIEnv *env, jobject jobj) {
    //获取属性所在class对象
    jclass j_clz = env->GetObjectClass(jobj);
    //获取属性jfieldID
    jfieldID j_fid = env->GetFieldID(j_clz, "name", "Ljava/lang/String;");
    //创建新的jstring对象
    jstring jniName = env->NewStringUTF("Dian");
    //修改为 Dian
    env->SetObjectField(jobj, j_fid, jniName);
}
extern "C"
JNIEXPORT jobject JNICALL
Java_com_wuk_ndkdemo_MainActivity_createPoint(JNIEnv *env, jobject jobj) {
    //找到Point类com.wuk.ndkdemo
    jclass j_clzz = env->FindClass("com/wuk/ndkdemo/Point");
    //获取构造方法的jmethodID
    jmethodID j_mid = env->GetMethodID(j_clzz, "<init>", "(II)V");
    //创建Point对象
    jobject point = env->NewObject(j_clzz, j_mid, 23, 34);

    //获取Point对象中x的jfieldID
    jfieldID j_fid = env->GetFieldID(j_clzz, "x", "I");
    //修改x的值
    env->SetIntField(point, j_fid, 18);
    //获取方法的jmethodID
    jmethodID j_set_y_mid = env->GetMethodID(j_clzz, "setY", "(I)V");
    //调用setY方法修改y的值
    env->CallVoidMethod(point, j_set_y_mid, 18);
    return point;
}