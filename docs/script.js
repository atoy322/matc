window.onload = function () {
    var classes = document.getElementsByClassName("code");

    for(var i=0; i<classes.length; i++) {
        var elem = classes[i];
        set(elem);
    }
}

function set(elem) {
    var src = elem.getAttribute("src");
    var xhr = new XMLHttpRequest();
    xhr.open("GET", src);
    xhr.send();

    console.log(elem);

    xhr.onload = function() {
        elem.innerHTML = xhr.responseText;
    }
}
